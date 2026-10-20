#pragma once
#include <QDialog>
#include "ui_MemoryChannelEditor.h"
#include "Cat.h"
#include <vector>
#include <QStandardItemModel>
class MemoryChannelEditorUI :
    public QDialog
{
public:
    MemoryChannelEditorUI(QWidget* parent);
    ~MemoryChannelEditorUI();
    bool eventFilter(QObject* obj, QEvent* event);
    void btnAddRow_2_clicked();
    void AddMemoryChannel(Yaesu::Commands::FT891::MemoryChannelTagValue& val);
signals:
    void on_updated_memory_channel(Yaesu::Commands::FT891::MemoryChannelTagValue);

private slots:
    void clicked(QAbstractButton* button);

private:
    Ui::MemoryChannelEditor ui;
    std::vector<Yaesu::Commands::FT891::MemoryChannelTagValue> m_channels;
    QStandardItemModel m_model;
};

