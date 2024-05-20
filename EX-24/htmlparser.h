#ifndef HTMLPARSER_H
#define HTMLPARSER_H

#include <QObject>
#include <QList>
#include <QUrl>

class HTMLParser : public QObject
{
    Q_OBJECT

public:
    explicit HTMLParser(QObject *parent = nullptr);

signals:
    void urlsExtracted(const QList<QUrl> &urls);

public slots:
    void parseHtml(const QString &html);

private:
    QList<QUrl> extractUrls(const QString &html);
};

#endif // HTMLPARSER_H
