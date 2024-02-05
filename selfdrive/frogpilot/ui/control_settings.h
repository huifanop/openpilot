#pragma once

#include <set>

#include "selfdrive/frogpilot/ui/frogpilot_ui_functions.h"
#include "selfdrive/ui/qt/offroad/settings.h"
#include "selfdrive/ui/ui.h"

class FrogPilotControlsPanel : public FrogPilotListWidget {
  Q_OBJECT

public:
  explicit FrogPilotControlsPanel(SettingsWindow *parent);

signals:
  void closeParentToggle();
  void openParentToggle();

private:
  void hideEvent(QHideEvent *event);
  void hideSubToggles();
  void parentToggleClicked();
  void updateCarToggles();
  void updateMetric();
  void updateState(const UIState &s);
  void updateToggles();

  FrogPilotButtonIconControl *modelSelectorButton;

  FrogPilotDualParamControl *aggressiveProfile;
  FrogPilotDualParamControl *conditionalSpeedsImperial;
  FrogPilotDualParamControl *conditionalSpeedsMetric;
  FrogPilotDualParamControl *standardProfile;
  FrogPilotDualParamControl *relaxedProfile;

  std::set<QString> conditionalExperimentalKeys = {"CECurves", "CECurvesLead", "CESlowerLead", "CENavigation", "CEStopLights", "CESignal"};
  std::set<QString> fireTheBabysitterKeys = {"NoLogging", "MuteOverheated"};
  std::set<QString> laneChangeKeys = {};
  std::set<QString> lateralTuneKeys = {"ForceAutoTune"};
  std::set<QString> longitudinalTuneKeys = {"AccelerationProfile", "AggressiveAcceleration", "StoppingDistance"};
  std::set<QString> mtscKeys = {"DisableMTSCSmoothing", "MTSCAggressiveness", "MTSCCurvatureCheck", "MTSCLimit"};
  std::set<QString> qolKeys = {"DisableOnroadUploads", "HigherBitrate", "ReverseCruise"};
  std::set<QString> speedLimitControllerKeys = {};
  std::set<QString> visionTurnControlKeys = {};

  std::map<std::string, ParamControl*> toggles;

  Params params;
  Params paramsMemory{"/dev/shm/params"};

  bool isMetric = params.getBool("IsMetric");
  bool started = false;
};
