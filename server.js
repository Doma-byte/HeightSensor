const { SerialPort } = require("serialport");
const { ReadlineParser } = require("@serialport/parser-readline");

let port;

const getFinalReading = async (req, res) => {
  try {
    if (!port) {
      port = new SerialPort({ path: "COM5", baudRate: 9600 });
      const parser = port.pipe(new ReadlineParser({ delimiter: "\r\n" }));

      const readings = [];
      let count = 0;

      parser.on("data", (data) => {
        console.log("Data is " + data);
        const distanceCm = parseFloat(data.split(" ")[2]);
        if (count++ <= 10) {
          readings.push(distanceCm);
        } else if (readings.length > 0) {
          const averageReading =
            readings.reduce((sum, value) => sum + value, 0) / readings.length;
          readings.length = 0;
          count = 0;

          parser.removeAllListeners("data");
          res.status(200).json({
            reading: averageReading.toFixed(2),
            message: "Successfully Readout",
          });

          port.close((error) => {
            if (error) {
              console.error("Error closing the serial port:", error);
            } else {
              console.log("Serial port closed.");
              port = null;
            }
          });
        }
      });

      port.on("error", (error) => {
        console.error("Serial port error:", error);
        res.status(500).json({
          message: "An error occurred while reading from the serial port.",
        });
      });
    } else {
      res.status(400).json({
        message: "Serial port is already open.",
      });
    }
  } catch (error) {
    console.error("Error:", error);
    res.status(500).json({
      message: "An error occurred while processing the request.",
    });
  }
};

module.exports = {
  getFinalReading,
};