#include "htmlparser.h"
#include <QRegularExpression>

HTMLParser::HTMLParser(QObject *parent) : QObject(parent) {}

void HTMLParser::parseHtml(const QString &html)
{
    QList<QUrl> urls = extractUrls(html);
    emit urlsExtracted(urls);
}

QList<QUrl> HTMLParser::extractUrls(const QString &html)
{
    QList<QUrl> urls;
    QRegularExpression regex("(?i)\\b(?:href|src)\\s*=\\s*(?:\"([^\"]*)\"|'([^']*)'|([^'\">\\s]+))");
    QRegularExpressionMatchIterator i = regex.globalMatch(html);
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        for (int j = 1; j <= 3; ++j) {
            QString urlStr = match.captured(j);
            if (!urlStr.isEmpty()) {
                QUrl url(urlStr);
                if (url.isValid()) {
                    urls.append(url);
                }
            }
        }
    }
    return urls;
}
