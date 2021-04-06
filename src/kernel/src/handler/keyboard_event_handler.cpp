#include <system.hpp>

namespace handler
{
    void keyboardEventHandler(system::io::entity::KeyboardEvent event)
    {
        system::io::entity::TextScreen *tmScreen = system::global::instance::getTextScreen();
        system::io::entity::Keyboard *kb = system::global::instance::getKeyboard();
        if (system::io::entity::Key::A <= event.key && event.key <= system::io::entity::Key::Z)
        {
            char str[2];
            if (kb->getCapsLockStatus() == system::io::entity::KeyStatus::Down)
            {
                str[0] = (char)event.key - (char)system::io::entity::Key::A + 'A';
            }
            else
            {
                str[0] = (char)event.key - (char)system::io::entity::Key::A + 'a';
            }
            str[1] = '\0';
            tmScreen->print(str);
        }
        else if (system::io::entity::Key::D0 <= event.key && event.key <= system::io::entity::Key::D9)
        {
            char str[2];
            str[0] = (char)event.key - (char)system::io::entity::Key::D0 + '0';
            str[1] = '\0';
            tmScreen->print(str);
        }
        else if (system::io::entity::Key::CapsLock == event.key)
        {
            system::io::entity::KeyStatus status = kb->getCapsLockStatus();
            if (status == system::io::entity::KeyStatus::Up)
            {
                kb->setCapsLockStatus(system::io::entity::KeyStatus::Down);
            }
            else
            {
                kb->setCapsLockStatus(system::io::entity::KeyStatus::Up);
            }
        }
        else
        {
            // tmScreen->print("key: ")->print((uint64_t)event.key);
        }
    }
} // namespace handler
