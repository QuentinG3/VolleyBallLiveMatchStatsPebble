
var xhrRequest = function (url, type, callback) {
  var xhr = new XMLHttpRequest();
  xhr.onload = function () {
    callback(this.responseText);
  };
  xhr.open(type, url);
  xhr.send();
};

function sendMail(dictionnary){
  // Construct URL
  var url = "https://thawing-escarpment-40639.herokuapp.com/api/email";
  for(var i = 0;i<120;i++){
    url += "/" + dictionnary[i+""];
  }
  console.log(url);
  
  // Send request to OpenWeatherMap
  xhrRequest(url, 'GET', 
    function(responseText) {
      Pebble.showSimpleNotificationOnPebble("Email", JSON.parse(responseText).message);
    }      
  );
}





// Listen for when the watchface is opened
Pebble.addEventListener('ready', 
  function(e) {
    console.log('PebbleKit JS ready!');
   
  }
);

// Listen for when an AppMessage is received
Pebble.addEventListener('appmessage',
  function(e) {
    console.log(JSON.stringify(e.payload));
    console.log('AppMessage received!');
     sendMail(e.payload);
  }                     
);