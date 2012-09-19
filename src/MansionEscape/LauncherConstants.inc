//Raw String Literal, Syntax highlighting spinnt, weil C++11-Feature
std::string const Launcher::MainMenuText(
u8R"(MansionEscape Hauptmenü:
  (a)     Spiel Starten (Interface: %s, Model: %s)
  (b)     Spielstand löschen
  (c)     Interface wählen
  (d)     Model wählen

  (q)     Applikation beenden
)");

std::string const Launcher::SaveDeleteText(
u8R"(Der Spielstand von welchem Model soll gelöscht werden?
  (a)     XML
  (b)     DB

  (q)     Zurück zum Hauptmenü
)");

std::string const Launcher::SelectInterfaceText(
u8R"(Welches Interface soll verwendet werden?
  (g)     GUI
  (t)     TUI

  (q)     Zurück zum HauptMenü
)");

std::string const Launcher::SelectModelText(
u8R"(Welches Model soll verwendet werden?
  (d)   DB
  (x)   XML

  (q)   Zurück zum Hauptmenü
)");

std::string const Launcher::GUI("GUI");
std::string const Launcher::TUI("TUI");
std::string const Launcher::DB("DB");
std::string const Launcher::XML("XML");
