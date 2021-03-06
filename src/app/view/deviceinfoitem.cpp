#include "deviceinfoitem.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include <QPixmap>

#include "widgetutil.h"

DeviceInfoItem::DeviceInfoItem(const QString &name, const QString &device,
                               const QString &cap, int percent, QWidget *parent)
    : QWidget(parent)
{
    auto mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(12, 0, 12, 0);
    mainLayout->setSpacing(0);

    m_deviceIcon = new QLabel;
    m_deviceIcon->setObjectName("DeviceInfoIcon");
    m_deviceIcon->setPixmap(s_removeDevice);

    auto m_deviceLabel = new QLabel;
    m_deviceLabel->setObjectName("DeviceInfoLabel");
    m_deviceLabel->setText(name);

    auto m_deviceDevName = new QLabel;
    m_deviceDevName->setObjectName("DeviceInfoDevName");
    m_deviceDevName->setText(QString("(%1)").arg(device));

    auto m_deviceCapacity = new QLabel;
    m_deviceCapacity->setObjectName("DeviceInfoCapacity");
    m_deviceCapacity->setText(cap);

    auto m_deviceCapacityBar = new QProgressBar;
    m_deviceCapacityBar->setObjectName("DeviceInfoCapacityBar");
    m_deviceCapacityBar->setTextVisible(false);
    m_deviceCapacityBar->setFixedSize(60, 6);
    m_deviceCapacityBar->setValue(percent);

    mainLayout->addWidget(m_deviceIcon, 0, Qt::AlignCenter);
    mainLayout->addSpacing(14);
    mainLayout->addWidget(m_deviceLabel, 0, Qt::AlignCenter);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(m_deviceDevName, 0, Qt::AlignCenter);
    mainLayout->addStretch();
    mainLayout->addWidget(m_deviceCapacity, 0, Qt::AlignCenter);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(m_deviceCapacityBar, 0, Qt::AlignCenter);

    setFixedSize(390, 60);

    this->setStyleSheet(WidgetUtil::getQss(":/theme/light/DeviceInfoItem.theme"));
}

DeviceInfoItem::DeviceInfoItem(QWidget *parent) :
    DeviceInfoItem("Remove Device", "NULL", "0/0G", 0, parent)
{

}

void DeviceInfoItem::setCheck(bool flag)
{
    m_deviceIcon->setPixmap(flag ? s_selectDevice : s_removeDevice);
}
