//standard includes
#include <iostream>
//#include <conio.h>
#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>


//game specific includes
#include "Battle_Handler.h"
#include "Player.h"
#include "Monster.h"


int main()
{
    srand(time(NULL));
    sf::Texture texture;
    
    //-------------------GAME INITIALIZATIONS-----------------
    //Player 
    Player player;
    Player* p_player = &player;

    //Monster
    Monster monster;
    Monster* p_monster = &monster;

    //Battle Handler
    Battle_Handler event(p_player, p_monster, p_player);
    event.Get_Pointer_To_Player()->Set_Pointer_To_Battle_Handler(&event);
    event.Get_Pointer_To_Monster()->Set_Pointer_To_Battle_Handler(&event);

    
    


    //------------------------TESTS-------------------------------
    //battle_handler.Start_Battle();
   

    //Create the main window
    sf::RenderWindow window(sf::VideoMode(1000, 800), "ALABWA");

    //Load a sprites to display

    //player
    sf::Texture player_texture;
    if (!player_texture.loadFromFile("data/Images/player.png"))
        return EXIT_FAILURE;
    sf::Sprite player_sprite(player_texture);
    player_sprite.setPosition(100, 100);

    //punch
    sf::Texture punch_texture;
    if (!punch_texture.loadFromFile("data/Images/player_Punch.png"))
        return EXIT_FAILURE;
   


    //minion
    sf::Texture minion_texture;
    if (!minion_texture.loadFromFile("data/Images/minion.png"))
        return EXIT_FAILURE;
    sf::Sprite minion_sprite(minion_texture);
    minion_sprite.setPosition(600, 130);

    //user interface
    
    //attack button
    sf::Texture attack_btn_texture;
    if (!attack_btn_texture.loadFromFile("data/Images/attack_button.png"))
        return EXIT_FAILURE;
    sf::Sprite attack_btn_sprite(attack_btn_texture);
    attack_btn_sprite.setPosition(100, 500);
 

    //defend button
    sf::Texture defend_btn_texture;
    if (!defend_btn_texture.loadFromFile("data/Images/defend_button.png"))
        return EXIT_FAILURE;
    sf::Sprite defend_btn_sprite(defend_btn_texture);
    defend_btn_sprite.setPosition(100, 550);

    //heal button
    sf::Texture heal_btn_texture;
    if (!heal_btn_texture.loadFromFile("data/Images/heal_button.png"))
        return EXIT_FAILURE;
    sf::Sprite heal_btn_sprite(heal_btn_texture);
    heal_btn_sprite.setPosition(100, 600);

    //attack spell button
    sf::Texture attack_spell_btn_texture;
    if (!attack_spell_btn_texture.loadFromFile("data/Images/attack_spell_button.png"))
        return EXIT_FAILURE;
    sf::Sprite attack_spell_btn_sprite(attack_spell_btn_texture);
    attack_spell_btn_sprite.setPosition(100, 650);
   
    //resistance spell button
    sf::Texture resistance_spell_btn_texture;
    if (!resistance_spell_btn_texture.loadFromFile("data/Images/resistance_spell_button.png"))
        return EXIT_FAILURE;
    sf::Sprite resistance_spell_btn_sprite(resistance_spell_btn_texture);
    resistance_spell_btn_sprite.setPosition(100, 700);

    //restart button
    sf::Texture restart_btn_texture;
    if (!restart_btn_texture.loadFromFile("data/Images/restart_button.png"))
        return EXIT_FAILURE;
    sf::Sprite restart_btn_sprite(restart_btn_texture);
    restart_btn_sprite.setTextureRect(sf::IntRect(0, 0, 178, 166));
    restart_btn_sprite.setPosition(425, 245);

    //mana lost hover
    sf::Sprite mana_bar_background_sprite_temp(player.Get_Mana_Bar_Background_Sprite()); //copy of mana bar background sprite

    
    /*-----------------BATTLE STILL RUNNING---------------------*/
    std::vector<sf::Sprite> ui_elements;
    ui_elements.push_back(attack_btn_sprite);
    ui_elements.push_back(defend_btn_sprite);
    ui_elements.push_back(heal_btn_sprite);
    ui_elements.push_back(attack_spell_btn_sprite);
    ui_elements.push_back(resistance_spell_btn_sprite);
    //ui_elements.push_back(mana_bar_background_sprite_temp);
   

    std::vector<Battle_Actor*> battle_actors;
    battle_actors.push_back(p_player);
    battle_actors.push_back(p_monster);

    /*-----------------BATTLE HAS ENDED---------------------*/
    std::vector<sf::Sprite> ui_elements_end_of_battle;
    ui_elements_end_of_battle.push_back(restart_btn_sprite);
    







   
    //Spunds to play
    //Battle sound
    sf::Music in_Fight;
    if (!in_Fight.openFromFile("data/Sounds/Fight/VALD - Gris Instrumental 2018 (1).ogg"))
        return EXIT_FAILURE;

    sf::Music player_Win;
    if (!player_Win.openFromFile("data/Sounds/Fight/Juice WRLD - That Summer (Music Video) Prod by Last Dude.ogg"))
        return EXIT_FAILURE;

    sf::Music player_Lose;
    if (!player_Lose.openFromFile("data/Sounds/Fight/XXTENTACION - Moonlight.ogg"))
        return EXIT_FAILURE;




    

   

   
  
  
    //Play Music
    //player_Win.play();
    //player_Lose.play();
   
    
    //Start the game loop
    while (window.isOpen())
    {

        if (player.Is_Alive() && monster.Is_Alive())
        {
            
            if (in_Fight.getStatus() != 2)
            {
                in_Fight.play();
            }
            
            sf::Event event;

            //Check if there is an event 
            while (window.pollEvent(event))
            {
                switch (event.type)
                {

                    //if user clicks on the red cross exit window button 
                case sf::Event::Closed:
                    window.close();
                    break;

                    //if user clicks on left mouse button
                case sf::Event::MouseButtonPressed:
                    switch (event.mouseButton.button)
                    {

                    case::sf::Mouse::Left:
                        //and if it was performed onto the attack button
                        if (attack_btn_sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            std::cout << "attack button clicked on" << std::endl;
                            p_player->Attack_Physically(p_monster);
                            p_monster->React_To(p_player);
                            std::cout << "HP MONSTER:";  p_monster->Print_Hp();
                            std::cout << "HP PLAYER:";  p_player->Print_Hp();
                        }

                        //or defend button
                        else if (defend_btn_sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            std::cout << "defend button clicked on" << std::endl;
                            p_player->Defend();
                            p_monster->React_To(p_player);
                            std::cout << "HP MONSTER:";  p_monster->Print_Hp();
                            std::cout << "HP PLAYER:";  p_player->Print_Hp();
                        }


                        //or heal button
                        else if (heal_btn_sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            std::cout << "heal button clicked on" << std::endl;
                            p_player->Heal();
                            p_monster->React_To(p_player);
                            std::cout << "HP MONSTER:";  p_monster->Print_Hp();
                            std::cout << "HP PLAYER:";  p_player->Print_Hp();
                        }


                        //or attack spell button
                        else if (attack_spell_btn_sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            std::cout << "attack spell button clicked on" << std::endl;
                            p_player->Cast_Attack_Spell(p_monster);
                            p_monster->React_To(p_player);
                            std::cout << "HP MONSTER:";  p_monster->Print_Hp();
                            std::cout << "HP PLAYER:";  p_player->Print_Hp();
                        }

                        //or resistance spell button
                        else if (resistance_spell_btn_sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            std::cout << "resistance spell button clicked on" << std::endl;
                            p_player->Cast_Res_Spell();
                            p_monster->React_To(p_player);
                            std::cout << "HP MONSTER:";  p_monster->Print_Hp();
                            std::cout << "HP PLAYER:";  p_player->Print_Hp();
                        }
                        break;

                    default:
                        break;
                    }


                default:
                    break;
                }
            }

            //Check mouse position
            int mouse_x = sf::Mouse::getPosition(window).x;
            int mouse_y = sf::Mouse::getPosition(window).y;
            //std::cout << "x:" << mouse_x << "  y:" << mouse_y << std::endl;


            //----------ATTACK SPELL BUTTON BOX-------------------//
            bool mouse_has_entered_attack_spell_button = false;
            int attack_spell_button_width = attack_spell_btn_texture.getSize().x * attack_spell_btn_sprite.getScale().x;
            int attack_spell_button_height = attack_spell_btn_texture.getSize().y * attack_spell_btn_sprite.getScale().y;
            sf::IntRect attack_spell_button_box(attack_spell_btn_sprite.getPosition().x, attack_spell_btn_sprite.getPosition().y, attack_spell_button_width, attack_spell_button_height);

            //----------RES SPELL BUTTON BOX-------------------//
            bool mouse_has_entered_res_spell_button = false;
            int res_spell_button_width = resistance_spell_btn_texture.getSize().x * resistance_spell_btn_sprite.getScale().x;
            int res_spell_button_height = resistance_spell_btn_texture.getSize().y * resistance_spell_btn_sprite.getScale().y;
            sf::IntRect res_spell_button_box(resistance_spell_btn_sprite.getPosition().x, resistance_spell_btn_sprite.getPosition().y, res_spell_button_width, res_spell_button_height);

            //----------HEALING SPELL BUTTON BOX-------------------//
            bool mouse_has_entered_healing_spell_button = false;
            int healing_spell_button_width = heal_btn_texture.getSize().x * heal_btn_sprite.getScale().x;
            int healing_spell_button_height = heal_btn_texture.getSize().y * heal_btn_sprite.getScale().y;
            sf::IntRect heal_button_box(heal_btn_sprite.getPosition().x, heal_btn_sprite.getPosition().y, healing_spell_button_width, healing_spell_button_height);



            //Check which spell button box has been entered
            if (attack_spell_button_box.contains(mouse_x, mouse_y))
            {
                mouse_has_entered_attack_spell_button = true;
            }
            else if (res_spell_button_box.contains(mouse_x, mouse_y))
            {
                mouse_has_entered_res_spell_button = true;
            }
            else if (heal_button_box.contains(mouse_x, mouse_y))
            {
                mouse_has_entered_healing_spell_button = true;
            }


            //Clear screen
            window.clear(sf::Color::White);

            //Updates
            for (auto p_battle_act : battle_actors)
            {
                p_battle_act->Update();
            }

            if (mouse_has_entered_attack_spell_button)
            {
                //Check if player has enough mana to cast spell
                if (player.Get_Mana() >= 30)
                {
                    player.Set_Visible_Hover_Of_Mana_Cost_Of_Attack_Spell(true);
                }


                else
                {
                    //show hover of hp lost if player cast spell without enough mana    
                    player.Set_Visible_Hover_Of_Hp_Lost_Sprite(true);
                }

            }
            else if (mouse_has_entered_res_spell_button)
            {
                //Check if player has enough mana to cast spell
                if (player.Get_Mana() >= 20)
                {
                    player.Set_Visible_Hover_Of_Mana_Cost_Of_Resistance_Spell(true);
                    player.Set_Visible_Hover_Of_Res_Gain_Of_Res_Spell(true);

                }

                else
                {
                    //show hover of hp lost if player cast spell without enough mana    
                    player.Set_Visible_Hover_Of_Hp_Lost_Sprite(true);
                }
            }
            else if (mouse_has_entered_healing_spell_button)
            {
                //Check if player has enough mana to cast spell
                if (player.Get_Mana() >= 50)
                {
                    player.Set_Visible_Hover_Of_Mana_Cost_Of_Healing_Spell(true);
                    player.Set_Visible_Hover_Of_Res_Gain_Of_Healing_Spell(true);
                    //player.Set_Visible_Hover_Of_Hp_Gain_Of_Healing_Spell(true);

                }

                else
                {
                    //show hover of hp lost if player cast spell without enough mana    
                    player.Set_Visible_Hover_Of_Hp_Lost_Sprite(true);
                }
            }
            else if (!mouse_has_entered_attack_spell_button && !mouse_has_entered_res_spell_button && !mouse_has_entered_healing_spell_button)
            {
                player.Set_Visible_Hover_Of_Hp_Lost_Sprite(false);
                player.Set_Visible_Hover_Of_Res_Gain_Of_Res_Spell(false);
                player.Set_Visible_Hover_Of_Res_Gain_Of_Healing_Spell(false);
                //player.Set_Visible_Hover_Of_Hp_Gain_Of_Healing_Spell(false);
            }




            //Draw all
            for (auto ui_element : ui_elements)
            {
                window.draw(ui_element);
            }


            for (auto p_battle_act : battle_actors)
            {
                p_battle_act->Draw(window);
            }


            //Update the window
            window.display();

        }

        else if (!player.Is_Alive() || !monster.Is_Alive())
        {

            in_Fight.stop();
            
            if (!monster.Is_Alive())
            {
                if (player_Win.getStatus() != 2)
                {
                    player_Win.play();
                }
               
                player.Set_Victory(true);
            }

            else if (!player.Is_Alive())
            {
                if (player_Lose.getStatus() != 2)
                {
                    player_Lose.play();
                }

                monster.Set_Victory(true);
            }

            else if(!player.Is_Alive() && !monster.Is_Alive())
            {
                if (in_Fight.getStatus() != 2)
                {
                    in_Fight.play();
                }
            }

            sf::Event event;

            //Check if there is an event 
            while (window.pollEvent(event))
            {
                switch (event.type)
                {

                    //if user clicks on the red cross exit window button 
                case sf::Event::Closed:
                    window.close();
                    break;

                    //if user clicks on left mouse button
                case sf::Event::MouseButtonPressed:
                    switch (event.mouseButton.button)
                    {

                    case::sf::Mouse::Left:
                        //and if it was performed onto the restart button
                        if (restart_btn_sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            //reset sounds
                            player_Lose.stop();
                            player_Win.stop();


                            std::cout << "-----------------PLAYER------------------------------" << std::endl;
                            std::cout << "before restart" << std::endl;
                            std::cout << "player alive:" << std::boolalpha << player.Is_Alive() << std::endl;
                            std::cout << "player is victorious:" << std::boolalpha << player.Is_Victorious() << std::endl;
                            std::cout << "resistance:" << player.Get_Resistance() << std::endl;
                            std::cout << "hp:" << player.Get_Hp() << std::endl;
                            std::cout << "mana:" << player.Get_Mana() << std::endl << std::endl;

                            
                            //reset player
                            player.Set_Is_Alive(true);
                            player.Set_Victory(false);

                            player.Set_Resistance(0.1);
                            player.Set_Hp(100);
                            player.Set_Mana(100);
                            player.Set_Default_Action(true);
                      

                            std::cout << "after restart" << std::endl;
                            std::cout << "player alive:" << std::boolalpha << player.Is_Alive() << std::endl;
                            std::cout << "player is victorious:" << std::boolalpha << player.Is_Victorious() << std::endl;
                            std::cout << "resistance:" << player.Get_Resistance() << std::endl;
                            std::cout << "hp:" << player.Get_Hp() << std::endl;
                            std::cout << "mana:" << player.Get_Mana() << std::endl << std::endl << std::endl;


                            //reset minion
                            std::cout << "---------------------MONSTER--------------------------" << std::endl;
                            std::cout << "before restart" << std::endl;
                            std::cout << "monster alive:" << std::boolalpha << monster.Is_Alive() << std::endl;
                            std::cout << "monster is victorious:" << std::boolalpha << monster.Is_Victorious() << std::endl;
                            std::cout << "resistance:" << monster.Get_Resistance() << std::endl;
                            std::cout << "hp:" << monster.Get_Hp() << std::endl;
                            std::cout << "mana:" << monster.Get_Mana() << std::endl << std::endl;

                            monster.Set_Is_Alive(true);
                            monster.Set_Victory(false);
                            monster.Set_Resistance(0.1);
                            monster.Set_Hp(100);
                            monster.Set_Mana(0);
                            monster.Set_Default_Action(true);

                            std::cout << "before restart" << std::endl;
                            std::cout << "monster alive:" << std::boolalpha << monster.Is_Alive() << std::endl;
                            std::cout << "monster is victorious:" << std::boolalpha << monster.Is_Victorious() << std::endl;
                            std::cout << "resistance:" << monster.Get_Resistance() << std::endl;
                            std::cout << "hp:" << monster.Get_Hp() << std::endl;
                            std::cout << "mana:" << monster.Get_Mana() << std::endl << std::endl;
                            
                            
                        }
                    default:
                        break;
                    }
                }

                //Check mouse position
                int mouse_x = sf::Mouse::getPosition(window).x;
                int mouse_y = sf::Mouse::getPosition(window).y;
                //std::cout << "x:" << mouse_x << "  y:" << mouse_y << std::endl;


                //----------RESTART BUTTON BOX-------------------//
                bool mouse_has_entered_restart_button = false;
                int restart_button_width = restart_btn_texture.getSize().x * restart_btn_sprite.getScale().x;
                int restart_button_height = restart_btn_texture.getSize().y * restart_btn_sprite.getScale().y;
                sf::IntRect restart_button_box(restart_btn_sprite.getPosition().x, restart_btn_sprite.getPosition().y, restart_button_width, restart_button_height);

                //Clear screen
                window.clear(sf::Color::White);

                //Updates
                for (auto p_battle_act : battle_actors)
                {
                    p_battle_act->Update();
                }

                /*if (mouse_has_entered_restart_button)
                {
                    std::cout << "restart button hovered" << std::endl;
                }
                */

                for (auto p_battle_act : battle_actors)
                {
                    p_battle_act->Draw(window);
                }
                
                //Draw all
                for (auto ui_element : ui_elements_end_of_battle)
                {
                    window.draw(ui_element);
                }

                //Update the window
                window.display();
            }
        }    
    }
    return EXIT_SUCCESS;
}













