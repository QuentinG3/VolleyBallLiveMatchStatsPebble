/*
Author : Quentin Gusbin
Date : 10/09/2016
*/
var xhrRequest = function (url, type, callback) {
  var xhr = new XMLHttpRequest();
  xhr.onload = function () {
    callback(this.responseText);
  };
  xhr.open(type, url);
  xhr.send();
};

function sendMail(dictionnary){
  // We construct the request to send the mail with the stats
  var url = "https://thawing-escarpment-40639.herokuapp.com/api/email";
  for(var i = 0;i<120;i++){
    url += "/" + dictionnary[i+""];
  }
  url += "/" + dictionnary["130"];
  console.log(url);
  // Send request to OpenWeatherMap
  xhrRequest(url, 'GET', 
    function(responseText) {
      //Show a notification on the watch with the result of the 
      Pebble.showSimpleNotificationOnPebble("Email", JSON.parse(responseText).message);
    }      
  );
}

// Listen for when an AppMessage is received
Pebble.addEventListener('appmessage',
  function(e) {
    //Sending the dictionnary with all the match data to the server.
    //The server will send a mail with a recap of the match
    console.log(JSON.stringify(e.payload));
    sendMail(e.payload);
  }                     
);