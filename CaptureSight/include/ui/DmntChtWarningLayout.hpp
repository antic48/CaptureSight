#pragma once

#include <pu/Plutonium>

class DmntChtWarningLayout : public pu::ui::Layout {
 public:
  DmntChtWarningLayout();
  PU_SMART_CTOR(DmntChtWarningLayout)

  void SetWarningText(std::string warning);

 private:
  pu::ui::elm::TextBlock::Ref warningTextBlock;
};