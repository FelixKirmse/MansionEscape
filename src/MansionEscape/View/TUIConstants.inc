//Raw String Literal, Syntax highlighting spinnt, weil C++11-Feature
std::string const TUI::MainMenuText(
u8R"(Was möchtest du tun?
  (1)     Untersuchen
  (2)     Bewegen
  (3)     Inventar

  (o)     Spiel-Optionen
)");

std::string const TUI::GameOptionsText(
u8R"(Spieloptionen:
  (1)     Speichern
  (2)     Laden
  (3)     Spiel beenden

  (a)     Abbrechen
)");

std::string const TUI::MoveOptionsText(
u8R"(In welche Richtung möchtest du gehen?
  (v)     Vorwärts
  (l)     Nach links drehen
  (r)     Nach rechts drehen

  (a)     Abbrechen
)");

std::string const TUI::WrongInputErrorText(
u8R"(Falsche Eingabe, bitte noch einmal probieren)");
