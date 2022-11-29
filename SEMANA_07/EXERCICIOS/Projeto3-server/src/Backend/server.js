
// server
const app = require("./app");

app.listen( 8000,  "10.254.16.130", () =>
  console.log(`Server running on port ${ 8000}`)
);
