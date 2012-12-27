#include "processcontroller.h"

ProcessController::ProcessController(QString build_name, QObject *parent)
    : QProcess(parent), mNasmCompileCommand("nasm -f elf -g -F stabs "),
      mGdbCommandStart("gdb "), mGccCommand("gcc -o " + build_name + " "),
      mLdCommand("ld -o " + build_name + " ")

{
    mNasmIn = new QFile();
    mNasmOut = new QFile();
    mNasmIn->open(3, QIODevice::WriteOnly);
    mNasmOut->open(4, QIODevice::ReadOnly);
}

ProcessController::~ProcessController()
{
    mNasmIn->close();
    mNasmOut->close();

    delete mNasmIn;
    delete mNasmOut;
}
