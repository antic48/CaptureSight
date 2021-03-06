#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <utils/I18N.hpp>

std::string GetTranslationCode(SetLanguage languageCode) {
  switch (languageCode) {
    case SetLanguage_FR:
    case SetLanguage_FRCA:
      return "fr";
    case SetLanguage_ENUS:
    case SetLanguage_ENGB:
    default:
      return "en";
  }
}

I18N::I18N() {
  u64 languageCode = 0;
  SetLanguage language = SetLanguage_ENUS;

  setGetSystemLanguage(&languageCode);
  setMakeLanguage(languageCode, &language);
  this->LoadTranslations(language);
}

void I18N::LoadTranslations(SetLanguage language) {
  std::ifstream translations("romfs:/i18n/" + GetTranslationCode(language) + ".json");

  if (translations.good()) {
    translations >> this->translations;
  }

  translations.close();
}

std::string I18N::Translate(std::string word) {
  return this->translations["app"].value(word, word);
}

std::string I18N::Translate(std::string category, std::string word) {
  return this->translations.at(category).value(word, word);
}