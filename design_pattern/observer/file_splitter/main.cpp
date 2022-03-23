#include "main_form.h"

int main() {
    MainForm mainForm("path", 10);
    ProgressBar* progressBar = new ProgressBar();
    ProgressConsole* progressConsole = new ProgressConsole();
    ProgressPercent* progressPercent = new ProgressPercent();

    mainForm.add(progressBar);
    mainForm.add(progressConsole);
    mainForm.add(progressPercent);

    mainForm.buttonClick();

    cout << "remove ProgressBar\n";
    mainForm.remove(progressConsole);
    mainForm.buttonClick();
}