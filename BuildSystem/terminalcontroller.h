#ifndef TERMINALCONTROLLER_H
#define TERMINALCONTROLLER_H

#include <QFile>
#include <QProcess>

class TerminalController : public QProcess
{
    Q_OBJECT

public:
    explicit TerminalController(QString build_name, QObject * parent = 0);
    ~TerminalController();

    //overload the << and >> operators for communications


private:
    QString mNasmCompileCommand;
    QString mGdbCommandStart;
    QString mGccCommand32;
    QString mGccCommand64;
    QString mLdCommand32;
    QString mLdCommand64;
    QFile * mTerminalIn;
    QFile * mTerminalOut;


};

#endif // TERMINALCONTROLLER_H
