#pragma once

#include <QPushButton>

#include "system/hardware/hw.h"
#include "selfdrive/ui/qt/widgets/controls.h"

// SSH enable toggle
class SshToggle : public ToggleControl {
  Q_OBJECT

public:
//////////////////////////////////////////////////////////////////////////////////////
  //SshToggle() : ToggleControl(tr("開啟 SSH"), "", "", Hardware::get_ssh_enabled()) {
  SshToggle() : ToggleControl(tr("開啟 SSH"), "", "", true) {
//////////////////////////////////////////////////////////////////////////////////////
    QObject::connect(this, &SshToggle::toggleFlipped, [=](bool state) {
      Hardware::set_ssh_enabled(state);
    });
  }
};

// SSH key management widget
class SshControl : public ButtonControl {
  Q_OBJECT

public:
  SshControl();

private:
  Params params;

  void refresh();
  void getUserKeys(const QString &username, bool isUserInput);
};
