#include <system.hpp>

namespace handler {
void keyboardEventHandler(system::io::entity::KeyboardEvent event) {
    system::io::entity::TextScreen *ts =
        system::global::instance::getTextScreen();
    system::io::entity::Keyboard *kb =
        system::global::instance::getKeyboard();
    if(system::io::entity::Key::A <= event.key
       && event.key <= system::io::entity::Key::Z) {
        char str[2];
        if(kb->getCapsLockStatus()
           == system::io::entity::KeyStatus::Down) {
            ts->print((char)((char)event.key
                             - (char)system::io::entity::Key::A + 'A'));
        } else {
            ts->print((char)((char)event.key
                             - (char)system::io::entity::Key::A + 'a'));
        }
    } else if(system::io::entity::Key::D0 <= event.key
              && event.key <= system::io::entity::Key::D9) {
        char str[2];
        ts->print((char)((char)event.key
                         - (char)system::io::entity::Key::D0 + '0'));
    } else if(system::io::entity::Key::CapsLock == event.key) {
        system::io::entity::KeyStatus status = kb->getCapsLockStatus();
        if(status == system::io::entity::KeyStatus::Up) {
            kb->setCapsLockStatus(system::io::entity::KeyStatus::Down);
        } else {
            kb->setCapsLockStatus(system::io::entity::KeyStatus::Up);
        }
    } else if(system::io::entity::Key::Space == event.key) {
        ts->print(' ');
    } else if(system::io::entity::Key::Enter == event.key) {
        ts->print('\n');
    } else if(system::io::entity::Key::Back == event.key) {
        ts->print('\b');
    }
}
} // namespace handler
