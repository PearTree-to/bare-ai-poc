const fs = require('fs');

const filePath = './file.txt';

fs.readFile(filePath, 'utf8', (err, data) => {
  if (err) {
    console.error('Error reading the file:', err);
    return;
  }

  console.log('File contents:', data);
});
