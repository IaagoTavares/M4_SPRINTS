
// server
const app = require("./app");

app.listen( 8000,  "10.128.64.17", () =>
  console.log(`Server running on port ${ 8000}`)
);