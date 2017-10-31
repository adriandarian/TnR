import "js/web.jsx";

class _Main {
  static function main(args : string[]) : void {
    var document = dom.window.document;
    var text = document.createTextNode("Hello, world!");
    document.getElementById("hello").appendChild(text);
  }
}
