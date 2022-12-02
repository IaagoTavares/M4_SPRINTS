exports.update = function (req, res) {
  console.log(req);

  res.status(200).end();
};

exports.postRequest = function (req, res) {
  console.log(req.body);

  fetch('url esp32', {

    method: 'POST',
        
    body:JSON.stringify({
      vencedor: req.body,
    })
  })

  // res.status(200).json({ "activated": "1" }).end();
};
