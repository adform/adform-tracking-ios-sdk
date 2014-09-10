function finishedLoading() {
  var iframe = document.createElement('iframe');
  iframe.setAttribute('src', 'loading:finished');
  document.documentElement.appendChild(iframe);
  iframe.parentNode.removeChild(iframe);
  iframe = null;
};
window.onload = function(){finishedLoading();};