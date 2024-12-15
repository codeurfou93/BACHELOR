const fs = require('fs');
const path = require('path');

function loggerMiddleware(req, res, next) {
    const log = `${new Date().toISOString()} - ${req.method} ${req.url}\n`;
    fs.appendFileSync(path.join(__dirname, '../../logs/requests.log'), log);
    next();
}

module.exports = loggerMiddleware;
