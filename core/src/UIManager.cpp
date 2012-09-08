#include "UIManager.h"

UIManager::UIManager(QWidget* parent):
    QMainWindow(parent),
    tabs_(new QTabWidget(this)) {
    setCentralWidget(tabs_);
    setVisible(true);
    setWindowTitle("Tibia Hook");

    resize(1000, 800);
}

void UIManager::addTab(QWidget* tab, const QString& label) {
    tabs_->addTab(tab, label);
}

void UIManager::removeTab(QWidget* tab) {
    int index = tabs_->indexOf(tab);
    if (index != -1) {
        tabs_->removeTab(index);
    }
}
