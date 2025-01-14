const express = require("express");
const tagsRouter = require("./routers/tagsRouter");
const updateRouter = require("./routers/updateRouter");
const morgan = require("morgan");
const cors = require('cors');

////////////////////////////////////////////////////////////////////////

const app = express();

// middlewares
// app.use(express.json()); // adds body to request
app.use(express.json({
    type: ['application/json', 'text/plain']
  }))

app.use(cors());

if (process.env.NODE_ENV == "development") app.use(morgan("dev")); // http requests logger

// routers
app.use("/api/v1/tags", tagsRouter);
app.use("/api/v1/update", updateRouter);

module.exports = app;
