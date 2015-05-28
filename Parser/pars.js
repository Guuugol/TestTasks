
var processString = function(str) {};

var parser = function ()
{
    var open_next_file = function ()
    {
        return {content: content, filename: filename, filetype: filetype}
    };

    var haveNextFile = function (){};

    var parseTxt = function (content)
    {
        var x = 0;
        var length = content.length;
        var str = '';
        var arr = [];
        while (x < length)
        {
            symbol = content.charAt(x);
            if (symbol == '\n')
            {
                var li = document.createElement('li');
                li.innerHTML = str;
                str = '';
                processString(str);
                arr.push(li);
            }
            else
            {
                str += symbol;
            }
        }
    };

    var parseXml = function (content) {};

    var knownTypes = new Object();
    knownTypes["txt"] = parseTxt;
    knownTypes["xml"] = parseXml;

    var content = {};

    this.loadFiles = function ()
    {
        var newContent = {};
        while (haveNextFile())
        {
            file = open_next_file();
            content[file.filename] = parse(file.content, filetype);
            newContent[file.filename] = parse(file.content, filtype);
        }
        return newContent;

    };

    var parse = function (content, filetype)
    {
        if (filetype in knownTypes)
        {
            knownTypes[filetype](content)
        }
        else
        {
            console.error('Unknown file type', filetype);
            return null;
        }

    };

    var addNewTypes = function(filetype, newParser)
    {
        knownTypes[filetype] = newParser;
    };

    var body = document.getElementsById('content');
    var parser = new Parser();
    var totalLines = 0;
    var maxLines = 500 * 10 / 12.5;
    var intervalFunction = function ()
    {
        var parser = new Parser();
        var res = parser.loadFiles();
        for (i = 0; i < 10; i++)
        {
            if (totalLines++ < maxLines)
            {
                body.appendChild(res[i]);
            }
        }
    };
    setInterval(intervalFunction, 5000);
};