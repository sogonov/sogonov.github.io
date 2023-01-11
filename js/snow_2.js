
var javascriptSnow = {

	begin: function() {
	
				this_ = this;
		window.onload = function () {
		
			var screen_size = this_.screen_size();
			   this_.swidth = screen_size[0];
			  this_.sheight = screen_size[1];
			   this_.amount = parseInt((this_.swidth*this_.sheight)/15700);
				 var images = 3;
			
			for(var index = 0; index < this_.amount; index++) {
				 var left = Math.round(this_.swidth*Math.random())-14;
				  var top = Math.round(this_.sheight*Math.random());
				switch( Math.round( 2*Math.random() ) ){
					case 0:
						var picture = 'snow_o';
						break;
					case 1:
						var picture = 'snow_oo';
						break;
					case 2:
						var picture = 'snow_ooo';
						break;
				}
				images += '<img id="crystal_'+index+'" class="crystal" src="images/'+picture+'.png" style="left: '+left+'px; top: '+top+'px;" />';
			}
			
			document.body.innerHTML = (document.body.innerHTML)+images+'<style type="text/css">.crystal{position:absolute;}</style>';
			
			setInterval(function() {
				for(var index = 0; index < this_.amount; index++) {
					  var obj = document.getElementById("crystal_"+index);
					var stobj = obj.style;
					  var top = parseInt(stobj.top.substring(0, stobj.top.length-2));
					if( top > this_.sheight-35 ) {
						this_.new_(obj, index);
					} else {
							var nm = obj.src.match(/(\w+\.png)/);
						switch( nm[1] ) {
							case "ooo.gif":
								top += 5;
								break;
							case "oo.gif":
								top += 3;
								break;
							default:
								top += 1;
						}
						stobj.top = top+"px";
					}
				}
			}, 30);
		};
	},
	
	new_: function(obj, index) {
		switch( Math.round(2*Math.random()) ){
			case 0:
				obj.src = "img/bus.png";
				break;
			case 1:
				obj.src = "img/bus1.png";
				break;
			case 2:
				obj.src = "img/bush.png";
				break;
		}
		obj.style.left = (Math.round(this_.swidth*Math.random())-14)+"px";
		obj.style.top = "0px";
	},
	
	screen_size: function() {
		var scr_x, scr_y ;
		var wn_x, wn_y ;
		if( window.innerHeight && window.scrollMaxY ) {
			scr_x = document.body.scrollWidth;
			scr_y = window.innerHeight + window.scrollMaxY ;
		} else if ( document.body.scrollHeight > document.body.offsetHeight ) {
			scr_x = document.body.scrollWidth;
			scr_y = document.body.scrollHeight;
		} else if ( document.documentElement && document.documentElement.scrollHeight > document.documentElement.offsetHeight ) {
			scr_x = document.documentElement.scrollWidth;
			scr_y = document.documentElement.scrollHeight;
		} else { 
			scr_x = document.body.offsetWidth;
			scr_y = document.body.offsetHeight;
		}
		if ( self.innerHeight ) { 
			wn_x = self.innerWidth;
			wn_y = self.innerHeight;
		} else if ( document.documentElement && document.documentElement.clientHeight ) {
			wn_x = document.documentElement.clientWidth;
			wn_y = document.documentElement.clientHeight;
		} else if ( document.body ) { 
			wn_x = document.body.clientWidth;
			wn_y = document.body.clientHeight;
		}
		if( scr_x < wn_x ) { w = wn_x; } else { w = scr_x; }
		if( scr_y < wn_y ) { h = wn_y; } else { h = scr_y; }
		return [ w, h ];
	}
};

javascriptSnow.begin();
