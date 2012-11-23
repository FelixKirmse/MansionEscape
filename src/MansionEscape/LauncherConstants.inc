//Raw String Literal, Syntax highlighting spinnt, weil C++11-Feature
std::string const Launcher::MainMenuText(
u8R"(MansionEscape Hauptmenü:
  (a)     Spiel Starten (Interface: %s, Model: %s, Spielstand: %d)
  (b)     Spielstand löschen
  (c)     Interface wählen
  (d)     Model wählen
  (e)     Spielstand wählen

  (q)     Applikation beenden
)");

std::string const Launcher::SaveDeleteText(
u8R"(Der Spielstand von welchem Model soll gelöscht werden?
  (a)     XML
  (b)     DB

  (c)   ALLE Spielstände in allen Models löschen

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

std::string const Launcher::SaveSlotText(
u8R"(Welcher Spielstand soll verwendet werden?
  (1)
  (2)
  (3)
  (4)
  (5)
  (6)
  (7)
  (8)
  (9)

  (q)   Zurück zum Hauptmenü
)");

std::string const Launcher::GUI("GUI");
std::string const Launcher::TUI("TUI");
std::string const Launcher::DB("DB");
std::string const Launcher::XML("XML");
