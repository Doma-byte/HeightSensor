const { SerialPort, ReadlineParser } = require('serialport')
const port = new SerialPort({ path: 'COM5', baudRate: 9600 })
const parser = new ReadlineParser()
port.pipe(parser)
parser.on('data', console.log)
port.write('ROBOT PLEASE RESPOND\n')
