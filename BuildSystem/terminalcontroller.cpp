#include "terminalcontroller.h"

TerminalController::TerminalController(QString build_name, QObject *parent)
    : QProcess(parent), mNasmCompileCommand("nasm -f elf -g -F stabs "),
      mGdbCommandStart("gdb "), mGccCommand32("gcc -o " + build_name + " "),
      mGccCommand64("gcc -m32 -o " + build_name + " "),
      mLdCommand32("ld -o " + build_name + " "),
      mLdCommand64("ld -melf_i386 -o " + build_name + " ")
{
    mTerminalIn = new QFile();
    mTerminalOut = new QFile();
    mTerminalIn->open(3, QIODevice::WriteOnly);
    mTerminalOut->open(4, QIODevice::ReadOnly);

}

TerminalController::~TerminalController()
{
    mTerminalIn->close();
    mTerminalOut->close();

    delete mTerminalIn;
    delete mTerminalOut;
}
