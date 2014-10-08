var map = L.map('map').setView([40.718, -73.99],13);
var RatsData;
		L.tileLayer('https://{s}.tiles.mapbox.com/v3/{id}/{z}/{x}/{y}.png', {
			maxZoom: 18,
			attribution: 'Map data &copy; <a href="http://openstreetmap.org">OpenStreetMap</a> contributors, ' +
				'<a href="http://creativecommons.org/licenses/by-sa/2.0/">CC-BY-SA</a>, ' +
				'Imagery © <a href="http://mapbox.com">Mapbox</a>',
			id: 'examples.map-20v6611k'
		}).addTo(map);

       
// control that shows the rat sightings data 
		
    var info = L.control();

		info.onAdd = function (map) {
			this._div = L.DomUtil.create('div', 'info');
			this.update();
			return this._div;
		};

		info.update = function (props) {
			this._div.innerHTML = '<h4>Where are the rats in NYC</h4>' +  (props ?
				'<b>' + props.Descriptor + '</b><br />' + props.IncidentAddress + '<br />' + props.LocationType +'<sup>2</sup>'
				: 'Hover over a marker');
		};

		info.addTo(map);

// Creating the interactive functions for the geoJson layer

function style(feature, latlng){
    return{
    radius: 6,
    fillColor: "#ffc400",
    color: "#000",
    weight: 1,
    opacity: 0,
    fillOpacity: 0.5
    }};

function highlightFeature(e) {
        var layer = e.target;
    
    layer.setStyle({
        radius: 10,
        fillColor: "#ff0a00",
        color: "#000",
        weight: 1,
        opacity: 0,
        fillOpacity: 1
    });
    
    if (!L.Browser.ie && !L.Browser.opera){
        layer.bringToFront();
    }
    info.update(layer.feature.properties);
}

var geojson;

function resetHighlight(e) {
    geojson.resetStyle(e.target),
        info.update();
}
    

function onEachFeature(feature, layer) {
			layer.on({
				mouseover: highlightFeature,
				mouseout: resetHighlight,
			});
            layer.bindPopup('<img src="RatLogo1.png"/> <br /> "Squeak!"');
}



geojson = L.geoJson(RatsData, {
			style: style,
			onEachFeature: onEachFeature,
        pointToLayer: function (feature, latlng) {
        return L.circleMarker(latlng, style);
    }
		}).addTo(map);
    

		map.attributionControl.addAttribution('Rat Sighting Data from 311 calls of Summer 2014 in NYC');


