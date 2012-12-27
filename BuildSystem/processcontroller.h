#ifndef PROCESSCONTROLLER_H
#define PROCESSCONTROLLER_H

#include <QFile>
#include <QProcess>
class ProcessController : public QProcess
{
    Q_OBJECT

public:
    explicit ProcessController(QString build_name, QObject * parent = 0);
    ~ProcessController();

private:


    QString mNasmCompileCommand;
    QString mGdbCommandStart;
    QString mGccCommand;
    QString mLdCommand;
    QFile * mNasmIn;
    QFile * mNasmOut;

};

#endif // TERMINALCONTROLLER_H
