#include <ui/DmntChtWarningLayout.hpp>
#include <utils/Settings.hpp>
#include <utils/I18N.hpp>

extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

DmntChtWarningLayout::DmntChtWarningLayout() : Layout::Layout() {
  this->warningTextBlock = pu::ui::elm::TextBlock::New(300, 350, i18n->Translate("Atmosphere's dmnt:cht is not running!\nPress + to close"), 30);
  this->warningTextBlock->SetColor(gsets.GetTheme().text.light);
  this->Add(this->warningTextBlock);
}