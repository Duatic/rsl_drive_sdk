^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package rsl_drive_sdk
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

2.0.0 (2026-11-05)
------------------
* feat!: brake support: setBrakeTargetState and getBrakeCurrentState with BrakeState replace
  setBrakeMode, getBrakeMode, setBrakeDuty and getBrakeDuty
* feat: asynchronous calibration
* feat: an ostream operator for BrakeState
* feat: support ROS 2 lyrical
* feat: build on soem_vendor, with its newer SOEM
* fix: a dangling iterator over the drive modes
* refactor: follow the rename to ecat_sdk_master (#13)
* refactor: use stream style logging
* docs: fix the README title
