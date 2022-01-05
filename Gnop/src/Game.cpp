#include "Game.h"



Game::Game() : _player(10.f), _world(_gravity)
{
    //_gameWorldEntityPtrs.push_back(_player.getPtr());
    _settings.getGameWindow().setKeyRepeatEnabled(false);
    _settings.getGameWindow().setMouseCursorVisible(true);
    _settings.getGameWindow().setFramerateLimit(60);
    _gravity.x = 0;
    _gravity.y = 9.8f;
    _world.SetGravity(_gravity);
    _fontForTextLevel.loadFromFile("data/Fonts/arial.ttf"); 
    _fontForLevelUp.loadFromFile("data/Fonts/ARCADECLASSIC.TTF");
    _fontForwave.loadFromFile("data/Fonts/arial.ttf");
    _fontForMoney.loadFromFile("data/Fonts/arial.ttf");
    _textureOfMoney.loadFromFile("data/kymio.png");
    _textureOfEmptyXpBar.loadFromFile("data/xp.png");
    _textureOfFullXp.loadFromFile("data/xpFull.png");
    _textureOfIncreaseSpeed.loadFromFile("data/Player/speedIncrease.png");
    _textureOfIncreaseAttack.loadFromFile("data/Player/attackIncrease.png");
    _textureOfIncreaseMaxHp.loadFromFile("data/Player/maxHpIncrease.png");
    _textureOfLevelUp.loadFromFile("data/Player/levelUpView.png");
    _textureOfStore.loadFromFile("data/storetext.png");
    _textureOfPriceBoxForItems.loadFromFile("data/storePrice.png");
    _textureOfHealItem.loadFromFile("data/healItem.png");
    _textureOfReductionDamageItem.loadFromFile("data/ReductionDamageItem.png");
   // _textureOfDefendingWallItem.loadFromFile("data/defendingWallItem.png");
    _textureOfDictacticielLeftMovement.loadFromFile("data/dictacticielLeft.png");
    _textureOfDictacticielRightMovement.loadFromFile("data/dictacticielRight.png");
    _textureOfDictacticielUpMovement.loadFromFile("data/dictacticielUp.png");
    _textureOfDictacticielDownMovement.loadFromFile("data/dictacticielDown.png");
    //_textureOfDictacticielAttackMovementRed.loadFromFile("data/dictacticielAttackRed.png");
    //_textureOfDictacticielAttackMovementWhite.loadFromFile("data/dictacticielAttackWhite.png");
    _textureOfDictacticielAttackMovementRed2.loadFromFile("data/dictacticielAttackRed2.png");
    _textureOfDictacticielAttackMovementWhite2.loadFromFile("data/dictacticielAttackWhite2.png");
    _textureOfGameOver.loadFromFile("data/playerLose.png");
    _textureOfRestartButton.loadFromFile("data/restartButton.png");
    _textureOfWin.loadFromFile("data/playerWin.png");
    _textureOfStartingDirection.loadFromFile("data/startingDirection.png");
    _textureOfPlayerHealingState.loadFromFile("data/playerHealing.png");
    _textureOfFlipperUnlocked.loadFromFile("data/FlipperUnlocked.png");
    _textureOfDashUnlocked.loadFromFile("data/DashUnlocked.png");
    _textureOfRegenUnlocked.loadFromFile("data/RegenUnlocked.png");
    _textureOfWelcomeScreen.loadFromFile("data/welcomeScreen.png");
    _textureOfExplanationReactionSpeedEnemy.loadFromFile("data/explanationReactionSpeedEnemy.png");
    _textureOfPlayButton.loadFromFile("data/playButton.png");

    if (!_mainTheme.openFromFile("data/mainTheme.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _mainTheme.setVolume(2.5);
    _mainTheme.play();

    if (!_gameOverTheme.openFromFile("data/gameOverTheme.ogg"))
    {
        std::cout << "oups" << std::endl;
    }

    if (!_winTheme.openFromFile("data/winTheme.ogg"))
    {
        std::cout << "oups" << std::endl;
    }

    if (!_levelUpEffectBuffer.loadFromFile("data/levelUp.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _levelUpEffectSound.setBuffer(_levelUpEffectBuffer);
    if (!_levelUpXpGainEffectBuffer.loadFromFile("data/levelUpXpGain.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _levelUpXpGainEffectSound.setBuffer(_levelUpXpGainEffectBuffer);

    if (!_xpGainEffectBuffer.loadFromFile("data/xpGain.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _xpGainEffectSound.setBuffer(_xpGainEffectBuffer);

    if (!_moneySpentEffectBuffer.loadFromFile("data/moneySpent.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _moneySpentEffectSound.setBuffer(_moneySpentEffectBuffer);

    if (!_attackEffectBuffer.loadFromFile("data/attack.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _attackEffectSound.setBuffer(_attackEffectBuffer);


    if (!_bouncingEffectBuffer.loadFromFile("data/bouncing.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _bouncingEffectSound.setBuffer(_bouncingEffectBuffer);
    _bouncingEffectSound.setVolume(2.5);


    if (!_increaseAbilityEffectBuffer.loadFromFile("data/increaseAbility.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _increaseAbilityEffectSound.setBuffer(_increaseAbilityEffectBuffer);
  


    if (!_hitEnemyEffectBuffer.loadFromFile("data/hitEnemy.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _hitEnemyEffectSound.setBuffer(_hitEnemyEffectBuffer);


    if (!_dashEffectBuffer.loadFromFile("data/dash.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _dashEffectSound.setVolume(3.5);
    _dashEffectSound.setBuffer(_dashEffectBuffer);

    if (!_flipperEffectBuffer.loadFromFile("data/flipper.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _flipperEffectSound.setVolume(3.5);
    _flipperEffectSound.setBuffer(_flipperEffectBuffer);


    if (!_regenEffectBuffer.loadFromFile("data/regen.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _regenEffectSound.setVolume(10);
    _regenEffectSound.setBuffer(_regenEffectBuffer);


    if (!_ballSmallingEffectBuffer.loadFromFile("data/smalling.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _ballSmallingEffectSound.setVolume(2.5);
    _ballSmallingEffectSound.setBuffer(_ballSmallingEffectBuffer);



    if (!_ballGrowingEffectBuffer.loadFromFile("data/growing.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _ballGrowingEffectSound.setVolume(2.5);
    _ballGrowingEffectSound.setBuffer(_ballGrowingEffectBuffer);




    

   

    _waveText.setFont(_fontForwave);
    _waveText.setCharacterSize(60);
    _waveText.setString("WAVE " + std::to_string(_wave) + " (training) ");
    
    _waveText.setFillColor(sf::Color::White);
    _waveText.setOutlineColor(sf::Color::Black);
    _waveText.setOutlineThickness(10);
    _waveText.setStyle(sf::Text::Regular);
    _waveText.setPosition(_settings.getBattleAreaBorders().getPosition().x +  _settings.getWidthOfBattleAreaBorders() / 2 -  2 * _waveText.getCharacterSize(), _settings.getBattleAreaBorders().getPosition().y - _waveText.getCharacterSize() - 17);   
    //wave Ui

    _spriteOfMoney.setTexture(_textureOfMoney);
    float widthMoney = _textureOfMoney.getSize().x;
    float heighMoney = _textureOfMoney.getSize().y;
    _spriteOfMoney.setOrigin(widthMoney / 2, heighMoney / 2);
    _spriteOfMoney.setPosition(0,0);
    _moneyText.setFont(_fontForMoney);
    _moneyText.setCharacterSize(40);
    _moneyText.setString(std::to_string((int)_money));
    _moneyText.setFillColor(sf::Color::White);
    _moneyText.setOutlineColor(sf::Color::Black);
    _moneyText.setOutlineThickness(3);
    _moneyText.setStyle(sf::Text::Regular);
    _moneyText.setPosition(0,0);  //money UI

    _spriteOfEmptyXpBar.setTexture(_textureOfEmptyXpBar);
    float widthXp = _textureOfEmptyXpBar.getSize().x;
    float heightXp = _textureOfEmptyXpBar.getSize().y;
    _spriteOfEmptyXpBar.setOrigin(widthXp / 2, heightXp / 2);
    _spriteOfEmptyXpBar.setPosition(0, 0); 
    _spriteOfFullXp.setTexture(_textureOfFullXp);
    _spriteOfFullXp.setOrigin(widthXp / 2, heightXp / 2);
    _spriteOfEmptyXpBar.setPosition(0, 0); //XP ui

    float widthOfIncreaseSpeed = _textureOfIncreaseSpeed.getSize().x;
    float heightOfIncreaseSpeed = _textureOfIncreaseSpeed.getSize().y;
    _spriteOfIncreaseSpeed.setTexture(_textureOfIncreaseSpeed);
    _spriteOfIncreaseSpeed.setOrigin(widthOfIncreaseSpeed / 2, heightOfIncreaseSpeed / 2);
    _spriteOfIncreaseSpeed.setPosition(0, 0);
    _speedPointsText.setFont(_fontForTextLevel);
    _speedPointsText.setCharacterSize(15);
    _speedPointsText.setString("0");
    _speedPointsText.setFillColor(sf::Color::White);
    _speedPointsText.setOutlineColor(sf::Color(63,72,204));
    _speedPointsText.setOutlineThickness(4);
    _speedPointsText.setStyle(sf::Text::Regular);
    _speedPointsText.setPosition(0, 0); // speed points

    float widthOfIncreaseAttack = _textureOfIncreaseAttack.getSize().x;
    float heightOfIncreaseAttack = _textureOfIncreaseAttack.getSize().y;
    _spriteOfIncreaseAttack.setTexture(_textureOfIncreaseAttack);
    _spriteOfIncreaseAttack.setOrigin(widthOfIncreaseAttack / 2, heightOfIncreaseAttack / 2);
    _spriteOfIncreaseAttack.setPosition(0, 0);
    _attackPointsText.setFont(_fontForTextLevel);
    _attackPointsText.setCharacterSize(15);
    _attackPointsText.setString("0");
    _attackPointsText.setFillColor(sf::Color::White);
    _attackPointsText.setOutlineColor(sf::Color(197, 10, 52));
    _attackPointsText.setOutlineThickness(4);
    _attackPointsText.setStyle(sf::Text::Regular);
    _attackPointsText.setPosition(0, 0); // attack points

    float widthOfIncreaseMaxHp = _textureOfIncreaseMaxHp.getSize().x;
    float heightOfIncreaseMaxHp = _textureOfIncreaseMaxHp.getSize().y;
    _spriteOfIncreaseMaxHp.setTexture(_textureOfIncreaseMaxHp);
    _spriteOfIncreaseMaxHp.setOrigin(widthOfIncreaseMaxHp / 2, heightOfIncreaseMaxHp / 2);
    _spriteOfIncreaseMaxHp.setPosition(0, 0);
    _maxHpPointsText.setFont(_fontForTextLevel);
    _maxHpPointsText.setCharacterSize(15);
    _maxHpPointsText.setString("0");
    _maxHpPointsText.setFillColor(sf::Color::White);
    _maxHpPointsText.setOutlineColor(sf::Color(255, 176, 176));
    _maxHpPointsText.setOutlineThickness(4);
    _maxHpPointsText.setStyle(sf::Text::Regular);
    _maxHpPointsText.setPosition(0, 0); // maxHp points

    _spriteOfStore.setTexture(_textureOfStore);
    float widthStoreText = _textureOfStore.getSize().x;
    float heightStoreText = _textureOfStore.getSize().y;
    _spriteOfStore.setOrigin(widthStoreText / 2, heightStoreText / 2);
    float widthBattleArea = _settings.getWidthOfBattleAreaBorders();
    float heighBattleArea = _settings.getHeightOfBattleAreaBorders();
    float battleAreaX = _settings.getBattleAreaBorders().getPosition().x;
    float battleAreaY = _settings.getBattleAreaBorders().getPosition().y;
    _spriteOfStore.setPosition((widthBattleArea * 0.95), (0.20 * heighBattleArea) + heightStoreText); //store text

    _spriteOfHealItem.setTexture(_textureOfHealItem);
    float widthHealItem = _textureOfHealItem.getSize().x;
    float heightHealItem = _textureOfHealItem.getSize().y;
    _spriteOfHealItem.setOrigin(widthHealItem / 2, heightHealItem / 2);
    _spriteOfHealItem.setPosition(-100, -100);//heal item

    _spriteOfBoxPriceHealItem.setTexture(_textureOfPriceBoxForItems);
    float widthPriceBoxHealItem = _textureOfPriceBoxForItems.getSize().x;
    float heightPriceBoxHealItem = _textureOfPriceBoxForItems.getSize().y;
    _spriteOfBoxPriceHealItem.setOrigin(widthPriceBoxHealItem / 2, heightPriceBoxHealItem / 2);
    _spriteOfBoxPriceHealItem.setPosition(-100, -100);
    _spriteOfBoxPriceHealItem.setColor(sf::Color(255, 255, 128)); //heal item price box

    _healItemPrice.setFont(_fontForMoney);
    _healItemPrice.setString("0");
    _healItemPrice.setOutlineColor(sf::Color::Black);
    _healItemPrice.setOutlineThickness(-3);
    _healItemPrice.setFillColor(sf::Color::Black);
    _healItemPrice.setPosition(-100, -100);
    _spriteOfHealItemPriceDecoration.setTexture(_textureOfMoney);
    _spriteOfHealItemPriceDecoration.setScale(0.4, 0.4);
    float widthHealItemPriceDecoration = _textureOfMoney.getSize().x * _spriteOfHealItemPriceDecoration.getScale().x;
    float heightHealItemPriceDecoration = _textureOfMoney.getSize().y * _spriteOfHealItemPriceDecoration.getScale().y;
    _spriteOfHealItemPriceDecoration.setOrigin(widthHealItemPriceDecoration / 2, heightHealItemPriceDecoration / 2);
    _spriteOfHealItemPriceDecoration.setPosition(-100, -100);
    _spriteOfHealItemPriceDecoration.setColor(sf::Color(255, 255, 128)); //store decoration heal item

   _spriteOfReductionDamageItem.setTexture(_textureOfReductionDamageItem);
    float widthReductionDamageItem = _textureOfReductionDamageItem.getSize().x;
    float heightReductionDamageItem = _textureOfReductionDamageItem.getSize().y;
    _spriteOfReductionDamageItem.setOrigin(widthReductionDamageItem / 2, heightReductionDamageItem / 2);
    _spriteOfReductionDamageItem.setPosition(-100, -100);//ReductionDamage item

    _spriteOfBoxPriceReductionDamageItem.setTexture(_textureOfPriceBoxForItems);
    float widthPriceBoxReductionDamageItem = _textureOfPriceBoxForItems.getSize().x;
    float heightPriceBoxReductionDamageItem = _textureOfPriceBoxForItems.getSize().y;
    _spriteOfBoxPriceReductionDamageItem.setOrigin(widthPriceBoxReductionDamageItem / 2, heightPriceBoxReductionDamageItem / 2);
    _spriteOfBoxPriceReductionDamageItem.setPosition(-100, -100);
    _spriteOfBoxPriceReductionDamageItem.setColor(sf::Color(255, 255, 128)); //ReductionDamage item price box

    _reductionDamageItemPrice.setFont(_fontForMoney);
    _reductionDamageItemPrice.setString("0");
    _reductionDamageItemPrice.setOutlineColor(sf::Color::Black);
    _reductionDamageItemPrice.setOutlineThickness(-3);
    _reductionDamageItemPrice.setFillColor(sf::Color::Black);
    _reductionDamageItemPrice.setPosition(-100, -100);
    _spriteOfReductionDamageItemPriceDecoration.setTexture(_textureOfMoney);
    _spriteOfReductionDamageItemPriceDecoration.setScale(0.4, 0.4);
    float widthReductionDamageItemPriceDecoration = _textureOfMoney.getSize().x * _spriteOfReductionDamageItemPriceDecoration.getScale().x;
    float heightReductionDamageItemPriceDecoration = _textureOfMoney.getSize().y * _spriteOfReductionDamageItemPriceDecoration.getScale().y;
    _spriteOfReductionDamageItemPriceDecoration.setOrigin(widthReductionDamageItemPriceDecoration / 2, heightReductionDamageItemPriceDecoration / 2);
    _spriteOfReductionDamageItemPriceDecoration.setPosition(-100, -100);
    _spriteOfReductionDamageItemPriceDecoration.setColor(sf::Color(255, 255, 128)); //store decoration ReductionDamage  item


   /* _spriteOfDefendingWallItem.setTexture(_textureOfDefendingWallItem);
    float widthDefendingWallItem = _textureOfDefendingWallItem.getSize().x;
    float heightDefendingWallItem = _textureOfDefendingWallItem.getSize().y;
    _spriteOfDefendingWallItem.setOrigin(widthDefendingWallItem / 2, heightDefendingWallItem / 2);
    _spriteOfDefendingWallItem.setPosition(-100, -100);//fly item

    _spriteOfBoxPriceDefendingWallItem.setTexture(_textureOfPriceBoxForItems);
    float widthPriceBoxDefendingWallItem = _textureOfPriceBoxForItems.getSize().x;
    float heightPriceBoxDefendingWallItem = _textureOfPriceBoxForItems.getSize().y;
    _spriteOfBoxPriceDefendingWallItem.setOrigin(widthPriceBoxDefendingWallItem / 2, heightPriceBoxDefendingWallItem / 2);
    _spriteOfBoxPriceDefendingWallItem.setPosition(-100, -100);
    _spriteOfBoxPriceDefendingWallItem.setColor(sf::Color(255, 255, 128)); //fly item price box

    _defendingWallItemPrice.setFont(_fontForMoney);
    _defendingWallItemPrice.setString("0");
    _defendingWallItemPrice.setOutlineColor(sf::Color::Black);
    _defendingWallItemPrice.setOutlineThickness(-3);
    _defendingWallItemPrice.setFillColor(sf::Color::Black);
    _defendingWallItemPrice.setPosition(-100, -100);
    _spriteOfDefendingWallItemPriceDecoration.setTexture(_textureOfMoney);
    _spriteOfDefendingWallItemPriceDecoration.setScale(0.4, 0.4);
    float widthDefendingWallItemPriceDecoration = _textureOfMoney.getSize().x * _spriteOfDefendingWallItemPriceDecoration.getScale().x;
    float heightDefendingWallItemPriceDecoration = _textureOfMoney.getSize().y * _spriteOfDefendingWallItemPriceDecoration.getScale().y;
    _spriteOfDefendingWallItemPriceDecoration.setOrigin(widthDefendingWallItemPriceDecoration / 2, heightDefendingWallItemPriceDecoration / 2);
    _spriteOfDefendingWallItemPriceDecoration.setPosition(-100, -100);
    _spriteOfDefendingWallItemPriceDecoration.setColor(sf::Color(255, 255, 128)); //store decoration fly  item*/

    _spriteOfDictacticielLeftMovement.setTexture(_textureOfDictacticielLeftMovement);
    float widthLeftIndicatorDictacticiel = _textureOfDictacticielLeftMovement.getSize().x;
    float heightLeftIndicatorDictacticiel = _textureOfDictacticielLeftMovement.getSize().y;
    _spriteOfDictacticielLeftMovement.setOrigin(widthLeftIndicatorDictacticiel / 2, heightLeftIndicatorDictacticiel / 2);
    _spriteOfDictacticielLeftMovement.setPosition(battleAreaX + widthLeftIndicatorDictacticiel / 2 + 100, battleAreaY + heightLeftIndicatorDictacticiel / 2 + 30);


    _spriteOfDictacticielRightMovement.setTexture(_textureOfDictacticielRightMovement);
    float widthRightIndicatorDictacticiel = _textureOfDictacticielRightMovement.getSize().x;
    float heightRightIndicatorDictacticiel = _textureOfDictacticielRightMovement.getSize().y;
    _spriteOfDictacticielRightMovement.setOrigin(widthRightIndicatorDictacticiel / 2, heightRightIndicatorDictacticiel / 2);
    _spriteOfDictacticielRightMovement.setPosition(battleAreaX + widthRightIndicatorDictacticiel / 2 + 100, battleAreaY + heightRightIndicatorDictacticiel / 2 + 90);


    _spriteOfDictacticielUpMovement.setTexture(_textureOfDictacticielUpMovement);
    float widthUpIndicatorDictacticiel = _textureOfDictacticielUpMovement.getSize().x;
    float heightUpIndicatorDictacticiel = _textureOfDictacticielUpMovement.getSize().y;
    _spriteOfDictacticielUpMovement.setOrigin(widthUpIndicatorDictacticiel / 2, heightUpIndicatorDictacticiel / 2);
    _spriteOfDictacticielUpMovement.setPosition(battleAreaX + widthUpIndicatorDictacticiel / 6 + widthUpIndicatorDictacticiel / 2, battleAreaY + heightUpIndicatorDictacticiel / 2 + 218);


    _spriteOfDictacticielDownMovement.setTexture(_textureOfDictacticielDownMovement);
    float widthDownIndicatorDictacticiel = _textureOfDictacticielDownMovement.getSize().x;
    float heightDownIndicatorDictacticiel = _textureOfDictacticielDownMovement.getSize().y;
    _spriteOfDictacticielDownMovement.setOrigin(widthDownIndicatorDictacticiel / 2, heightDownIndicatorDictacticiel / 2);
    _spriteOfDictacticielDownMovement.setPosition(battleAreaX + widthDownIndicatorDictacticiel / 6 + widthDownIndicatorDictacticiel / 2, battleAreaY + heightDownIndicatorDictacticiel / 2 + 250);


    _spriteOfDictacticielAttackMovement.setTexture(_textureOfDictacticielAttackMovementWhite2);
    float widthAttackIndicatorDictacticiel = _textureOfDictacticielAttackMovementWhite2.getSize().x;
    float heightAttackIndicatorDictacticiel = _textureOfDictacticielAttackMovementWhite2.getSize().y;
    _spriteOfDictacticielAttackMovement.setOrigin(widthAttackIndicatorDictacticiel / 2, heightAttackIndicatorDictacticiel / 2);
    _spriteOfDictacticielAttackMovement.setPosition(battleAreaX + widthAttackIndicatorDictacticiel / 2 + 700, battleAreaY + heightAttackIndicatorDictacticiel + 300);


    _textNextWave.setFont(_fontForLevelUp);
    _textNextWave.setFillColor(sf::Color::Black);
    _textNextWave.setPosition(battleAreaX + widthBattleArea / 2 - 300, battleAreaY + 20);
    _textNextWave.setString("press  A  to  go  next  wave"); //next wave text

    _gameOverText.setFont(_fontForLevelUp);
    _gameOverText.setString("GAME OVER X");
    _gameOverText.setCharacterSize(100);
    _gameOverText.setPosition(-100, -100);
    _gameOverText.setFillColor(sf::Color::Black); //game over text

    _spriteOfGameOver.setTexture(_textureOfGameOver);
    float widthGameOverSprite = _textureOfGameOver.getSize().x;
    float heightGameOverSprite = _textureOfGameOver.getSize().y;
    _spriteOfGameOver.setOrigin(widthGameOverSprite / 2, heightGameOverSprite / 2);
    _spriteOfGameOver.setPosition(-100, -100);  //player giving up sprite

    _spriteOfRestartButton.setTexture(_textureOfRestartButton);
    float widthRestartButton = _textureOfRestartButton.getSize().x;
    float heightRestartButton = _textureOfRestartButton.getSize().y;
    _spriteOfRestartButton.setOrigin(widthRestartButton / 2, heightRestartButton / 2);
    _spriteOfRestartButton.setPosition(-100, -100); //restart button

    _winText.setFont(_fontForLevelUp);
    _winText.setString("YOU WIN X");
    _winText.setCharacterSize(100);
    _winText.setPosition(-100, -100);
    _winText.setFillColor(sf::Color::Black); //win text

    _spriteOfWin.setTexture(_textureOfWin);
    float widthWinSprite = _textureOfWin.getSize().x;
    float heightWinSprite = _textureOfWin.getSize().y;
    _spriteOfWin.setOrigin(widthWinSprite / 2, heightWinSprite / 2);
    _spriteOfWin.setPosition(-100, -100);  //player win sprite
   
    float widthStartingDirectionArrow = _textureOfStartingDirection.getSize().x;
    float heightStartingDirectionArrow = _textureOfStartingDirection.getSize().y; //starting direction arrow dims

    _spriteOfStartingDirectionRight.setTexture(_textureOfStartingDirection); 
    _spriteOfStartingDirectionRight.setOrigin(widthStartingDirectionArrow / 2, heightStartingDirectionArrow / 2);
    _spriteOfStartingDirectionRight.setPosition(-100, -100); // starting direction right

    _spriteOfStartingDirectionUpAndRight.setTexture(_textureOfStartingDirection);
    _spriteOfStartingDirectionUpAndRight.setOrigin(widthStartingDirectionArrow / 2, heightStartingDirectionArrow / 2);
    _spriteOfStartingDirectionUpAndRight.setPosition(-100, -100); // starting direction up and right


    _spriteOfStartingDirectionDownAndRight.setTexture(_textureOfStartingDirection);
    _spriteOfStartingDirectionDownAndRight.setOrigin(widthStartingDirectionArrow / 2, heightStartingDirectionArrow / 2);
    _spriteOfStartingDirectionDownAndRight.setPosition(-100, -100); // starting direction up and right

    _defendingWall.setPosition(battleAreaX + 0.1 * widthBattleArea, battleAreaY);
    _defendingWall.setSize(sf::Vector2f(heighBattleArea, 2.5));
    _defendingWall.setFillColor(sf::Color(198, 236, 238));
    _defendingWall.setRotation(90);


    _spriteOfFlipperUnlocked.setTexture(_textureOfFlipperUnlocked);
    _spriteOfFlipperUnlocked.setPosition(battleAreaX + 160, battleAreaY + 300); //flipper unlocked

    _spriteOfDashUnlocked.setTexture(_textureOfDashUnlocked);
    _spriteOfDashUnlocked.setPosition(battleAreaX + 160, battleAreaY + 300); //dash unlocked

    _spriteOfRegenUnlocked.setTexture(_textureOfRegenUnlocked);
    _spriteOfRegenUnlocked.setPosition(battleAreaX + 160, battleAreaY + 300); //regen unlocked

    float gameWindowX = _settings.getGameWindowBorders().getPosition().x;
    float gameWindowY = _settings.getGameWindowBorders().getPosition().y;
    _spriteOfWelcomeScreen.setTexture(_textureOfWelcomeScreen);
    _spriteOfWelcomeScreen.setPosition(gameWindowX, gameWindowY);

    _textAskingToPickDirection.setFont(_fontForLevelUp);
    _textAskingToPickDirection.setFillColor(sf::Color::Black);
    _textAskingToPickDirection.setPosition(-1000,-1000);
    _textAskingToPickDirection.setCharacterSize(45);
    _textAskingToPickDirection.setString("click  on  a  direction \n with  your  mouse! \n middle  by  default"); //text asking to pick direction during starting phase
   
    _textOfExplanationBallHitEnemy.setFont(_fontForLevelUp);
    _textOfExplanationBallHitEnemy.setFillColor(sf::Color::Black);
    _textOfExplanationBallHitEnemy.setPosition(-1000, -1000);
    _textOfExplanationBallHitEnemy.setCharacterSize(25);
    _textOfExplanationBallHitEnemy.setString("enemies  take  damage  if  they  get  hit  by  your  ball \n [click  to  pass] "); //explanation ball hit enemy


    _textOfExplanationBallHitPlayer.setFont(_fontForLevelUp);
    _textOfExplanationBallHitPlayer.setFillColor(sf::Color::Black);
    _textOfExplanationBallHitPlayer.setPosition(-1000, -1000);
    _textOfExplanationBallHitPlayer.setCharacterSize(25);
    _textOfExplanationBallHitPlayer.setString("you  take  damages  if  you  get  hit  by  enemy  ball  \nbut  rest  assured! \n this  amount  of  damages  will  be  highly  reduced\n  in  case  you  stop  the  ball  from  touching  your  camp \n also  if  you  intercept  the ball  it activates "); //explanation ball hit player


    _theDefendingWallText.setFont(_fontForLevelUp);
    _theDefendingWallText.setFillColor(sf::Color(198,236,238));
    _theDefendingWallText.setPosition(-1000, -1000);
    _theDefendingWallText.setCharacterSize(25);
    _theDefendingWallText.setString("the  defending  wall");

    _textOfExplanationBallHitDefendingWall.setFont(_fontForLevelUp);
    _textOfExplanationBallHitDefendingWall.setFillColor(sf::Color::Black);
    _textOfExplanationBallHitDefendingWall.setPosition(-1000, -1000);
    _textOfExplanationBallHitDefendingWall.setCharacterSize(25);
    _textOfExplanationBallHitDefendingWall.setString("nullifies  the  next  enemy  attack  and  disappears  soon  after \n it  will  activate  itself  each  time  you  intercept  the  ball \n and  also  at  the  beggining  of  every  wave  so  use  it  wisely! \n[click  to  pass]"); //explanation defending wall



    _theRedZoneText.setFont(_fontForLevelUp);
    _theRedZoneText.setFillColor(sf::Color::Red);
    _theRedZoneText.setPosition(-1000, -1000);
    _theRedZoneText.setCharacterSize(25);
    _theRedZoneText.setString("the  red  zone"); // red zone text

    _theGreenZoneText.setFont(_fontForLevelUp);
    _theGreenZoneText.setFillColor(sf::Color::Green);
    _theGreenZoneText.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.3);
    _theGreenZoneText.setCharacterSize(25);
    _theGreenZoneText.setString("the  green  zone"); // green zone text

    _playerCampDescription.setFont(_fontForLevelUp);
    _playerCampDescription.setFillColor(sf::Color::Black);
    _playerCampDescription.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.22);
    _playerCampDescription.setCharacterSize(25);
    _playerCampDescription.setString("is  your  camp \n protect  it  from  enemy  attacks  "); // player camp description
     
    _textOfExplanationBallHitEnemyCamp.setFont(_fontForLevelUp);
    _textOfExplanationBallHitEnemyCamp.setFillColor(sf::Color::Black);
    _textOfExplanationBallHitEnemyCamp.setPosition(-1000, -1000);
    _textOfExplanationBallHitEnemyCamp.setCharacterSize(25);
    _textOfExplanationBallHitEnemyCamp.setString(" is  the  enemy  camp  \n all  enemies  take  damage  \n if  you  hit  their  camp  with  your  ball  \n [click  to  pass] "); //explanation ball hit enemy camp
   
    _textOfExplanationBallHitPlayerCamp.setFont(_fontForLevelUp);
    _textOfExplanationBallHitPlayerCamp.setFillColor(sf::Color::Black);
    _textOfExplanationBallHitPlayerCamp.setPosition(-1000, -1000);
    _textOfExplanationBallHitPlayerCamp.setCharacterSize(25);
    _textOfExplanationBallHitPlayerCamp.setString("hey  you!  bad  news  for  you ): \n you  lose  a  percentage  of  30  of  your  maximum  life  if  you  fail  to  intercept  the  ball \n when  the  ball  has  touched  enemy  camp \n this  situation  is  called  player  camp  getting  recked  by  enemy  camp  sorry  bud \n  [click  to  pass]"); //explanation ball hit player camp

    _textOfExplanationBallHitPlayerCamp2.setFont(_fontForLevelUp);
    _textOfExplanationBallHitPlayerCamp2.setFillColor(sf::Color::Black);
    _textOfExplanationBallHitPlayerCamp2.setPosition(-1000, -1000);
    _textOfExplanationBallHitPlayerCamp2.setCharacterSize(25);
    _textOfExplanationBallHitPlayerCamp2.setString("you  get  full  enemy  damages  if  your  camp  gets  hit  by  an  enemy  ball \n  [click  to  pass]");

    _textOfExplanationPlayerImmune.setFont(_fontForLevelUp);
    _textOfExplanationPlayerImmune.setFillColor(sf::Color::Black);
    _textOfExplanationPlayerImmune.setPosition(-1000, -1000);
    _textOfExplanationPlayerImmune.setCharacterSize(25);
    _textOfExplanationPlayerImmune.setString("hey  you  good  news  for  you  :) \n you  do  not  loose  any   life  if  you  succed  to  \n intercept  the  ball \n after  it  has  touched  enemy  camp \n  [click  to  pass]");//explanation player immune


    _textOfExplanationEnemiesTargetingPlayer.setFont(_fontForLevelUp);
    _textOfExplanationEnemiesTargetingPlayer.setFillColor(sf::Color::Black);
    _textOfExplanationEnemiesTargetingPlayer.setPosition(-1000, -1000);
    _textOfExplanationEnemiesTargetingPlayer.setCharacterSize(25);
    _textOfExplanationEnemiesTargetingPlayer.setString("Be careful! \n enemies   started   targeting   you\n it   usually  happens   when   they   reach   mid   life \n at   least   if   your   are   only   fighting   minions    hehe"); //explanation enemies targeting player


    _spriteOfExplanationReactionSpeedEnemy.setTexture(_textureOfExplanationReactionSpeedEnemy);
    

    _indicationForApproachingEnemies.setFont(_fontForLevelUp);
    _indicationForApproachingEnemies.setFillColor(sf::Color::Blue);
    _indicationForApproachingEnemies.setPosition(-1000, -1000);
    _indicationForApproachingEnemies.setCharacterSize(25);
    _indicationForApproachingEnemies.setString("try  tto  get  near  an  enemy");

    _spriteOfPlayButton.setTexture(_textureOfPlayButton);
    _spriteOfPlayButton.setPosition(battleAreaX + widthBattleArea / 1.8, battleAreaY + heighBattleArea / 2);

    float groundYpos = _settings.getBattleAreaBorders().getPosition().y + _settings.getHeightOfBattleAreaBorders();
    float groundXpos = _settings.getBattleAreaBorders().getPosition().x;
    _groundBodyDef.position = b2Vec2(groundXpos / SCALE, groundYpos / SCALE);
    _groundBodyDef.type = b2_staticBody;
    b2Body* groundBody = _world.CreateBody(&_groundBodyDef);
    b2PolygonShape groundShape;
    groundShape.SetAsBox(10000.f / 2 / SCALE, 16.f / 2 / SCALE);
    b2FixtureDef groundFixtureDef;
    groundFixtureDef.density = 1.f;
    groundFixtureDef.shape = &groundShape;
    groundBody->CreateFixture(&groundFixtureDef);
    _ground.setSize(sf::Vector2f(_settings.getWidthOfBattleAreaBorders(), 16));
    _ground.setOrigin(_ground.getSize().x / 2, _ground.getSize().y / 2);
    _ground.setPosition(groundXpos + _settings.getWidthOfBattleAreaBorders() / 2, groundBody->GetPosition().y * SCALE);
    //_ground.setFillColor(sf::Color::Black); // create ground

    float leftWallYpos = _settings.getBattleAreaBorders().getPosition().y;
    float leftWallXpos = _settings.getBattleAreaBorders().getPosition().x;
    _leftWallBodyDef.position = b2Vec2(leftWallXpos / SCALE, leftWallYpos / SCALE);
    _leftWallBodyDef.type = b2_staticBody;
    _leftWallBody = _world.CreateBody(&_leftWallBodyDef);
    b2PolygonShape leftWallShape;
    leftWallShape.SetAsBox(16.f / 2 / SCALE, _settings.getHeightOfBattleAreaBorders() / SCALE);
    b2FixtureDef leftWallFixtureDef;
    leftWallFixtureDef.density = 1.f;
    leftWallFixtureDef.shape = &leftWallShape;
    _leftWallBody->CreateFixture(&leftWallFixtureDef);
    _leftWall.setSize(sf::Vector2f(16, _settings.getHeightOfBattleAreaBorders()));
    //_leftWall.setOrigin(_leftWall.getSize().x / 2, _leftWall.getSize().y / 2);
    _leftWall.setPosition(_leftWallBody->GetPosition().x * SCALE, _leftWallBody->GetPosition().y * SCALE);
    _leftWall.setFillColor(sf::Color::Green); // create leftWall

    float rightWallYpos = _settings.getBattleAreaBorders().getPosition().y;
    float rightWallXpos = _settings.getBattleAreaBorders().getPosition().x + _settings.getWidthOfBattleAreaBorders();
    _rightWallBodyDef.position = b2Vec2(rightWallXpos / SCALE, rightWallYpos / SCALE);
    _rightWallBodyDef.type = b2_staticBody;
    b2Body* rightWallBody = _world.CreateBody(&_rightWallBodyDef);
    b2PolygonShape rightWallShape;
    rightWallShape.SetAsBox(16.f / 2 / SCALE, _settings.getHeightOfBattleAreaBorders() / SCALE);
    b2FixtureDef rightWallFixtureDef;
    rightWallFixtureDef.density = 1.f;
    rightWallFixtureDef.shape = &rightWallShape;
    rightWallBody->CreateFixture(&rightWallFixtureDef);
    _rightWall.setSize(sf::Vector2f(16, _settings.getHeightOfBattleAreaBorders()));
    _rightWall.setOrigin(_rightWall.getSize().x / 2, _rightWall.getSize().y / 2);
    _rightWall.setPosition(rightWallXpos, rightWallBody->GetPosition().y * SCALE + _settings.getHeightOfBattleAreaBorders() / 2);
    _rightWall.setFillColor(sf::Color::Red); // create rightWall


    float ceilingYpos = _settings.getBattleAreaBorders().getPosition().y;
    float ceilingXpos = _settings.getBattleAreaBorders().getPosition().x;
    _ceilingBodyDef.position = b2Vec2(ceilingXpos / SCALE, ceilingYpos / SCALE);
    _ceilingBodyDef.type = b2_staticBody;
    b2Body* ceilingBody = _world.CreateBody(&_ceilingBodyDef);
    b2PolygonShape ceilingShape;
    ceilingShape.SetAsBox(1000 / SCALE, 16 / 2 / SCALE);
    b2FixtureDef ceilingFixtureDef;
    ceilingFixtureDef.density = 1.f;
    ceilingFixtureDef.shape = &ceilingShape;
    ceilingBody->CreateFixture(&ceilingFixtureDef);
    _ceiling.setSize(sf::Vector2f(_settings.getWidthOfBattleAreaBorders(), 16));
    _ceiling.setOrigin(_ceiling.getSize().x / 2, _ceiling.getSize().y / 2);
    _ceiling.setPosition(ceilingBody->GetPosition().x * SCALE + _settings.getWidthOfBattleAreaBorders() /2, ceilingBody->GetPosition().y * SCALE);
    //_ceiling.setFillColor(sf::Color::Black); // create ceiling


    float widthBall = _ball.getTexture().getSize().x * _ball.getSprite().getScale().x;
    float heightBall = _ball.getTexture().getSize().y * _ball.getSprite().getScale().y;
    _ball.getBodyDef().position = b2Vec2(groundXpos / SCALE + widthBall / 2 / SCALE - _outlineThickness / SCALE + 300 / SCALE, 300 / SCALE);
    b2Body* ballBody = _world.CreateBody(&_ball.getBodyDef());
    _ball.setBody(ballBody);
    _ball.getBody()->CreateFixture(&_ball.getFixtureDef());
    _ball.getBody()->SetLinearDamping(0.f); 
    _ball.getCollider().setPosition(300, 300);
    //_ball.isGoingRight(true);
    //_ball.isGoingUp(true); //setup ball

    for (int i = 0; i < 3;i++)
    {
        Bloc bloc;
        bloc.getCollider().setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 150 + rand() % 100));
        bloc.setId(i);
        _blocsInStore.push_back(std::move(bloc));
    }  //setup blocs
    Bloc blocTemplate;
    float widthBloc = blocTemplate.getCollider().getSize().x;
    float heightBloc = blocTemplate.getCollider().getSize().y;
    //sf::FloatRect blocsContainer;
    //float widthContainer = _settings.getWidthOfBattleAreaBorders();
    //float containerXpos = _settings.getBattleAreaBorders().getPosition().x;
    //bloc.getCollider().setPosition(blocXpos, blocYpos); //TODO


    srand(time(NULL));
    inits();
    run();
}
Game::Game(Player player) : _world(_gravity)
{
    _settings.getGameWindow().setKeyRepeatEnabled(false);
	_settings.getGameWindow().setFramerateLimit(60);
    srand(time(NULL));
    _player = player;
    inits();
    run();
}

Game::~Game() = default;

void Game::gameOver()
{
    _settings.getGameWindow().setMouseCursorVisible(true);
    if (_mainTheme.getStatus() == 2)
    {
        _mainTheme.stop();
    }

    if (_gameOverTheme.getStatus() != 2)
    {
        _gameOverTheme.play();
        _gameOverTheme.setVolume(2.5);
    }

    float widthBattleArea = _settings.getWidthOfBattleAreaBorders();
    float heighBattleArea = _settings.getHeightOfBattleAreaBorders();
    float battleAreaX = _settings.getBattleAreaBorders().getPosition().x;
    float battleAreaY = _settings.getBattleAreaBorders().getPosition().y;
    _gameOverText.setPosition(battleAreaX + widthBattleArea / 2 - _gameOverText.getCharacterSize() - 125, battleAreaY + heighBattleArea / 3.5 - _gameOverText.getCharacterSize()); //game over text

    float gameOverTextX = _gameOverText.getPosition().x;
    float gameOverTextY = _gameOverText.getPosition().y;
    float widthGameOverSprite = _textureOfGameOver.getSize().x;
    float heightGameOverSprite = _textureOfGameOver.getSize().y;
    _spriteOfGameOver.setPosition(gameOverTextX + widthGameOverSprite / 2, gameOverTextY + _gameOverText.getCharacterSize() + 100); //game over sprite

    float gameOverSpriteX = _spriteOfGameOver.getPosition().x;
    float gameOverSpriteY = _spriteOfGameOver.getPosition().y;
    float widthRestartButton = _textureOfRestartButton.getSize().x;
    float heightRestartButton = _textureOfRestartButton.getSize().y;
    _spriteOfRestartButton.setPosition(gameOverSpriteX + widthGameOverSprite / 2 + widthRestartButton, gameOverSpriteY);  //restart button

    _spawnPoints.erase(_spawnPoints.begin(), _spawnPoints.end());
    _enemies.erase(_enemies.begin(), _enemies.end());

    _upgradePhase = false;
    _playerHasLeveledUp = false;
    _waveIsInProgress = false;
    _startingPhase = false;
  
}

void Game::win()
{
    _settings.getGameWindow().setMouseCursorVisible(true);
    if (_mainTheme.getStatus() == 2)
    {
        _mainTheme.stop();
    }

    if (_winTheme.getStatus() != 2)
    {
        _winTheme.play();
        _winTheme.setVolume(2.5);
    }

    float widthBattleArea = _settings.getWidthOfBattleAreaBorders();
    float heighBattleArea = _settings.getHeightOfBattleAreaBorders();
    float battleAreaX = _settings.getBattleAreaBorders().getPosition().x;
    float battleAreaY = _settings.getBattleAreaBorders().getPosition().y;
    _winText.setPosition(battleAreaX + widthBattleArea / 2 - _winText.getCharacterSize() - 125, battleAreaY + heighBattleArea / 3.5 - _winText.getCharacterSize()); //game over text

    float winTextX = _winText.getPosition().x;
    float winTextY = _winText.getPosition().y;
    float widthwinSprite = _textureOfWin.getSize().x;
    float heightwinSprite = _textureOfWin.getSize().y;
    _spriteOfWin.setPosition(winTextX + widthwinSprite / 2, winTextY + _winText.getCharacterSize() + 120); //player win sprite

    float winSpriteX = _spriteOfWin.getPosition().x;
    float winSpriteY = _spriteOfWin.getPosition().y;
    float widthRestartButton = _textureOfRestartButton.getSize().x;
    float heightRestartButton = _textureOfRestartButton.getSize().y;
    _spriteOfRestartButton.setPosition(winSpriteX + widthwinSprite / 2 + widthRestartButton, winSpriteY);  //restart button

    _spawnPoints.erase(_spawnPoints.begin(), _spawnPoints.end());
    _enemies.erase(_enemies.begin(), _enemies.end());

     //_gameOver = false;
    _upgradePhase = false;
    _playerHasLeveledUp = false;
    _waveIsInProgress = false;
    _startingPhase = false;
   
}

void Game::restart()
{
    _settings.getGameWindow().setMouseCursorVisible(true);
    
   
    if (_mainTheme.getStatus() != 2)
    {
        _mainTheme.play();
    }

    if (_gameOverTheme.getStatus() == 2)
    {
        _gameOverTheme.stop();
    }

    if (_winTheme.getStatus() == 2)
    {
        _winTheme.stop();
    }
    Enemy::reset();

    _minAlphaInRange = 5;
    _maxAlphaInRange = 50;
    _nbOfAbiliyPoints = 0;
    _minEnemies = 1;
    _maxEnemies = 2;
    _nbAttackPoints = 0;
    _nbMaxHpPoints = 0;
    _nbSpeedPoints = 0;
    _wave = 1;
    _waveText.setString("WAVE " + std::to_string(_wave));
    std::cout << "jusque la tout va bien" << std::endl;

    initPlayer();
    initHealthBarPlayer();
    for (auto& player : _playerStorer)
    {
        std::cout << player.getMaxHp() << std::endl;
        player.setBaseMaxHp(99.9);
        std::cout << player.getMaxHp() << std::endl;
        player.setHp(player.getMaxHp());
    }

    initEnemies();
    initHealthBarsOfEnemies();
    initReactionTimeBarsOfEnemies();
    

    _startingPhase = true;
    _waveIsInProgress = false;
    _defendingWallIsActive = false;
    _ball.setCollisionWithEnemy(false);
    _ball.setCollisionWithEnemyCamp(false);
    _ball.setCollisionWithPlayer(false);
    _ball.setCollisionWithPlayerCamp(false);
    _ball.setCurrentSpeed(_ball.getBaseSpeed());
    _ball.isGoingDown(false);
    _ball.isGoingUp(false);
    _ball.isGoingRight(false);
    _ball.isGoingLeft(false);
    
}

bool Game::checkAnyCollisionBetweenBallAndEnemies()
{
    for (auto& enemy : _enemies)
    {
        if (_ball.getCollider().getGlobalBounds().intersects(enemy.getHitbox()))
        {
            return true;
        }
    }

    return false;
}

bool Game::checkPlayerEntersAnyEnemyRange()
{

    for (auto& enemy : _enemies)
    {
        for (auto& player: _playerStorer)
        {
            if (enemy.getRange().getGlobalBounds().intersects(player.getSprite().getGlobalBounds()))
            {
                return true;
            }
        }
       
    }

    return false;
}

void Game::updateXp()
{
    for (auto& player : _playerStorer)
    {
        if (_wave != 0)
        {
            if (player.getCurrentXp() >= player.getXpToLevelUp())
            {
                //std::cout << "player level:" << player.getLevel() << std::endl;
                player.levelUp();
                _playerHasLeveledUp = true;
                _levelUpEffectSound.play();
                _levelUpXpGainEffectSound.play();
                player.setCurrentXp(1);
                _timerLevelUp = 0;
                _iLevelUp = 0;
                player.setHp(player.getHp() + (0.40 * player.getMaxHp()));
                if (player.getHp() >= player.getMaxHp())
                {
                    player.setHp(player.getMaxHp());
                }
                _nbOfAbiliyPoints++;
            }
            else
            {

                float ratioOfCurrentXp = player.getCurrentXp() / player.getXpToLevelUp();
                float heightOfXpBar = _textureOfEmptyXpBar.getSize().y * _spriteOfEmptyXpBar.getScale().y;
                float maximumWidthOfXpBar = _textureOfEmptyXpBar.getSize().x * _spriteOfEmptyXpBar.getScale().x;
                float widthOfCurrentXpBar = ratioOfCurrentXp * maximumWidthOfXpBar;
                _spriteOfFullXp.setTextureRect(sf::IntRect(0, 0, widthOfCurrentXpBar, heightOfXpBar));
                //_spriteOfLevelUpView.setPosition(0,0);
            }
        }
      
    }
   
}

void Game::inits()
{
    
    //_ball.getCollider().setPosition(100, 100);
    initPlayer(); 
    initHealthBarPlayer();

    

    initEnemies();
    initHealthBarsOfEnemies();
    initReactionTimeBarsOfEnemies();
   
}

	
    void Game::initPlayer()
    {

        float widthOfPlayer = _player.getTexture().getSize().x;
        float heightOfBattleAreaBorders = _settings.getBattleAreaBorders().getSize().y;
        float posXOfBattleAreaBorders =  _settings.getBattleAreaBorders().getPosition().x - _outlineThickness + widthOfPlayer / 2.f;
        _player.setPosition(posXOfBattleAreaBorders, heightOfBattleAreaBorders / 2.f);
        _playerStorer.push_back(std::move(_player));
        std::cout << "player atk:" << _playerStorer.back().getAtk() << std::endl;
        std::cout << "player speed" << _playerStorer.back().getSpeed() << std::endl;
        std::cout << "player hp" << _playerStorer.back().getHealth().getHp() << std::endl;

        _playerStorer.back().getLevelText().setFont(_fontForTextLevel);
        _playerStorer.back().getLevelText().setFillColor(sf::Color::White);
        _playerStorer.back().getLevelText().setOutlineColor(sf::Color::Green);
        _playerStorer.back().getLevelText().setOutlineThickness(3);
        _playerStorer.back().getLevelText().setStyle(sf::Text::Bold);

        _spriteOfLevelUp.setTexture(_textureOfLevelUp);
        float widthOfOfLevelUp = _textureOfLevelUp.getSize().x;
        float heightOfOfLevelUp = _textureOfLevelUp.getSize().y;
        _spriteOfLevelUp.setOrigin(widthOfOfLevelUp / 2, heightOfOfLevelUp / 2);
        _spriteOfLevelUp.setPosition(0, 0);
        _textForLevelUp.setFont(_fontForLevelUp);
        _textForLevelUp.setCharacterSize(50);
        _textForLevelUp.setString("LEVEL UP!");
        _textForLevelUp.setPosition(-100, -100);
        _textForLevelUp.setFillColor(sf::Color::Black);//levelUp


        _spriteOfPlayerHealingState.setTexture(_textureOfPlayerHealingState);
        float widthOfOfHealingState = _textureOfPlayerHealingState.getSize().x;
        float heightOfOfHealingState = _textureOfPlayerHealingState.getSize().y;
        _spriteOfPlayerHealingState.setOrigin(widthOfOfHealingState / 2, heightOfOfHealingState / 2);
        _spriteOfPlayerHealingState.setPosition(-100, -100);//healing

        
       
       

        

    }
    void Game::initHealthBarPlayer()
    {
        //PLAYER HEALTH BAR
        for (auto& player : _playerStorer)
        {
            player.getHealthBarEmpty().setSize(sf::Vector2f(92, 15));
            float widthHealthbarEmpty = player.getHealthBarEmpty().getSize().x *player.getHealthBarEmpty().getScale().x;
            float heightHealthbarEmpty = player.getHealthBarEmpty().getSize().y * player.getHealthBarEmpty().getScale().y;
            player.getHealthBarEmpty().setOrigin(widthHealthbarEmpty / 2, heightHealthbarEmpty / 2);
            player.getHealthBarEmpty().setOutlineThickness(-1);
            player.getHealthBarEmpty().setOutlineColor(sf::Color::Black);
            player.getHealthBarEmpty().setPosition(-500, -500);

            player.getHealthbar().setSize(sf::Vector2f(widthHealthbarEmpty, heightHealthbarEmpty));
            player.getHealthbar().setOrigin(widthHealthbarEmpty / 2, heightHealthbarEmpty / 2);
            player.getHealthbar().setFillColor(sf::Color::Green);
            player.getHealthbar().setPosition(-500, -500);
        }
       

    }

    void Game::initEnemies()
    {
        /*
      TODO::
      -wave < 6 -> que des petits
      - wave [6;12[ 50/50 petits et moyens
      - wave [12;20[ 2/3 moyens et 1/3 gros
      - wave [20;40{ introduction des colorés & (3/4 des gros -- 0.7/4 moyens -- 0.3/4 petits
  */
        if (_wave == 0)
        {
            std::cout << "dicta" << std::endl;
            _nbEnemies = 1;
        } //dictacticiel

        if (_wave % 10 == 0 && _wave != 0)
        {
           
            _nbEnemies = 1;
        } //boss wave

        else if(_wave != 0)
        {
            do
            {
                _nbEnemies = _minEnemies + rand() % (_maxEnemies - _minEnemies + 1); // nbEnemies = nbSpawnPoints
            } while (_nbEnemies <= 0);
        }
	  
        if (_wave % 10 != 0 || _wave == 0)
        {
            std::cout << "common wave spawnpoints" << std::endl;
            float y = _settings.getBattleAreaBorders().getSize().y / _nbEnemies; // y is distance between origins of the enemies
            float battleAreaBordersTopRightXPosition = _settings.getBattleAreaBorders().getPosition().x
                + _settings.getBattleAreaBorders().getSize().x + _outlineThickness;

            float battleAreaBordersYPosition = _settings.getBattleAreaBorders().getPosition().y
                - _outlineThickness;


            float h = battleAreaBordersYPosition; //starting spawnPoint y pos
            int i = 0;
            while (i < _nbEnemies)
            {
                sf::FloatRect point(battleAreaBordersTopRightXPosition, h, 0.1f, 0.1f);
                _spawnPoints.push_back(point);
                h += y;
                i++;
            } //creating enemies spawn point
        }

        else
        {
            std::cout << "boss spawn point" << std::endl;
            float battleAreaBordersMiddleY = _settings.getHeightOfBattleAreaBorders() * 0.5;
            float battleAreaBordersTopRightXPosition = _settings.getBattleAreaBorders().getPosition().x
                + _settings.getWidthOfBattleAreaBorders() + _outlineThickness;
            sf::FloatRect spawnPointBoss(battleAreaBordersTopRightXPosition + 300, battleAreaBordersMiddleY + 100, 0.1f, 0.1f);
            _spawnPoints.push_back(spawnPointBoss);
        }//creating enmy boss pawn point
        

		
        /*
           TODO
           -wave < 6 -> que des petits
           - wave [6;12[ 50/50 petits et moyens
           - wave [12;20[ 2/3 moyens et 1/3 gros
           - wave [20;40{ introduction des colorés & (3/4 des gros -- 0.7/4 moyens -- 0.3/4 petits
         */

        if (_wave == 0)
        {
            int j = 0;
            while (j < _spawnPoints.size())
            {
                std::cout << "little sized" << std::endl;
                Enemy enemy;
                _enemies.push_back(std::move(enemy));
                _enemies.back().setSpriteScaleX(1.f);
                _enemies.back().setSpriteScaleY(1.f);
                _enemies.back().getBodySprite().setOrigin(_enemies.back().getBodyTexture().getSize().x * _enemies.back().getSpriteScaleX() / 2.f, _enemies.back().getBodyTexture().getSize().y * _enemies.back().getSpriteScaleY() / 2.f); //set origin
                _enemies.back().getBodySprite().setPosition(_spawnPoints[j].left, _spawnPoints[j].top);

                
                _enemies.back().setBaseAtk(5);
                _enemies.back().setBaseSpeed(0);
                _enemies.back().setBaseMaxHp(300);
                _enemies.back().setBaseXpDrop(0);
                _enemies.back().setBaseMoneyDrop(5);
                

                std::cout << "enemy random stats" << std::endl;
                _enemies.back().setMaxAtk(_enemies.back().getBaseAtk() + (1.1 * _enemies.back().getLevel()));
                _enemies.back().setMaxSpeed(1.1);
                _enemies.back().setMaxHp(_enemies.back().getBaseMaxHp() + (1.1 * _enemies.back().getLevel()));
                _enemies.back().setHp(_enemies.back().getMaxHp());
                float maxHp = _enemies.back().getMaxHp();
                _enemies.back().setHpLimit(maxHp / 2);
                
                std::cout << "atk: " << _enemies.back().getAtk() << std::endl;
                std::cout << "hp: " << _enemies.back().getHp() << std::endl;
                std::cout << "speed: " << _enemies.back().getSpeed() << std::endl;
                std::cout << "reaction time:" << _enemies.back().getReactionTime() << std::endl;

                j++;
            }       
        }


        else if (_wave < 5 && _wave > 0)
        {
            int j = 0;
            while (j < _spawnPoints.size())
            {
               
                std::cout << "little sized" << std::endl;
                Enemy enemy;
                _enemies.push_back(std::move(enemy));
                _enemies.back().setSpriteScaleX(1.f);
                _enemies.back().setSpriteScaleY(1.f);
                _enemies.back().getBodySprite().setOrigin(_enemies.back().getBodyTexture().getSize().x * _enemies.back().getSpriteScaleX() / 2.f, _enemies.back().getBodyTexture().getSize().y * _enemies.back().getSpriteScaleY() / 2.f); //set origin
                _enemies.back().getBodySprite().setPosition(_spawnPoints[j].left, _spawnPoints[j].top);

                _enemies.back().setBaseAtk(15);
                _enemies.back().setBaseSpeed(0);
                _enemies.back().setBaseMaxHp(50);
                _enemies.back().setBaseXpDrop(16.5);
                _enemies.back().setBaseMoneyDrop(20);

                std::cout << "enemy random stats" << std::endl;
                _enemies.back().setColor(sf::Color(0, 0, 0, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                float alpha = static_cast<float>(_enemies.back().getColor().a);
                _enemies.back().setMaxAtk(_enemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _enemies.back().getBaseAtk()) + (1.1 * _enemies.back().getLevel()));
                _enemies.back().setMaxSpeed(1.1 + (alpha / _ultimateAlpha));
                _enemies.back().setMaxHp(_enemies.back().getBaseMaxHp() + (alpha / _ultimateAlpha * _enemies.back().getBaseMaxHp()) + (1.1 * _enemies.back().getLevel()));
                _enemies.back().setHp(_enemies.back().getMaxHp());
                float maxHp = _enemies.back().getMaxHp();
                _enemies.back().setHpLimit(maxHp / 2);

                std::cout << "atk: " << _enemies.back().getAtk() << std::endl;
                std::cout << "hp: " << _enemies.back().getHp() << std::endl;
                std::cout << "speed: " << _enemies.back().getSpeed() << std::endl;
                std::cout << "reaction time:" << _enemies.back().getReactionTime() << std::endl;
                

                j++;
            }

        }

        else if (_wave >= 5 && _wave < 10)
        {
            int j = 0;
            while (j < _spawnPoints.size())
            {
                int rand__ = 0;
                do
                {
                    rand__ = rand() % 100; //100 is arbitrary
                } while (rand__ <= 0);

                if (rand__ > 0 && rand__ < 50)
                {
                    std::cout << "little sized" << std::endl;
                    Enemy enemy;
                    _enemies.push_back(std::move(enemy));
                    _enemies.back().setSpriteScaleX(1.f);
                    _enemies.back().setSpriteScaleY(1.f);
                    _enemies.back().getBodySprite().setOrigin(_enemies.back().getBodyTexture().getSize().x * _enemies.back().getSpriteScaleX() / 2.f, _enemies.back().getBodyTexture().getSize().y * _enemies.back().getSpriteScaleY() / 2.f); //set origin
                    _enemies.back().getBodySprite().setPosition(_spawnPoints[j].left, _spawnPoints[j].top);

                    _enemies.back().setBaseAtk(15);
                    _enemies.back().setBaseSpeed(0);
                    _enemies.back().setBaseMaxHp(50);
                    _enemies.back().setBaseXpDrop(16.5);
                    _enemies.back().setBaseMoneyDrop(20);

                    std::cout << "enemy random stats" << std::endl;
                    _enemies.back().setColor(sf::Color(0, 0, 0, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                    float alpha = static_cast<float>(_enemies.back().getColor().a);
                    _enemies.back().setMaxAtk(_enemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _enemies.back().getBaseAtk()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setMaxSpeed(1.1 + (alpha / _ultimateAlpha));
                    _enemies.back().setMaxHp(_enemies.back().getBaseMaxHp() + (alpha / _ultimateAlpha * _enemies.back().getBaseMaxHp()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setHp(_enemies.back().getMaxHp());
                    float maxHp = _enemies.back().getMaxHp();
                    _enemies.back().setHpLimit(maxHp / 2);

                    std::cout << "atk: " << _enemies.back().getAtk() << std::endl;
                    std::cout << "hp: " << _enemies.back().getHp() << std::endl;
                    std::cout << "speed: " << _enemies.back().getSpeed() << std::endl;
                    std::cout << "reaction time:" << _enemies.back().getReactionTime() << std::endl;

                }

                else if (rand__ >= 50)
                {
                    std::cout << "medium sized" << std::endl;
                    //MEDIUM SIZED ENEMY 
                    Enemy enemy;
                    _enemies.push_back(std::move(enemy));
                    _enemies.back().setSpriteScaleX(1.2f);
                    _enemies.back().setSpriteScaleY(1.3f);
                    _enemies.back().getBodySprite().setOrigin(_enemies.back().getBodyTexture().getSize().x * _enemies.back().getSpriteScaleX() / 2.f, _enemies.back().getBodyTexture().getSize().y * _enemies.back().getSpriteScaleY() / 2.f); //set origin
                    _enemies.back().getBodySprite().setPosition(_spawnPoints[j].left, _spawnPoints[j].top);

                    _enemies.back().setBaseAtk(35);
                    _enemies.back().setBaseSpeed(0);
                    _enemies.back().setBaseMaxHp(80);
                    _enemies.back().setBaseXpDrop(22);
                    _enemies.back().setBaseMoneyDrop(30);

                    std::cout << "enemy random stats" << std::endl;
                    _enemies.back().setColor(sf::Color(0, 0, 0, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                    float alpha = static_cast<float>(_enemies.back().getColor().a);
                    _enemies.back().setMaxAtk(_enemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _enemies.back().getBaseAtk()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setMaxSpeed(1.1 + (alpha / _ultimateAlpha));
                    _enemies.back().setMaxHp(_enemies.back().getBaseMaxHp() + (alpha / _ultimateAlpha * _enemies.back().getBaseMaxHp()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setHp(_enemies.back().getMaxHp());
                    float maxHp = _enemies.back().getMaxHp();
                    _enemies.back().setHpLimit(maxHp / 2);

                    std::cout << "atk: " << _enemies.back().getAtk() << std::endl;
                    std::cout << "hp: " << _enemies.back().getHp() << std::endl;
                    std::cout << "speed: " << _enemies.back().getSpeed() << std::endl;
                    
                }

                j++;
            }
           
        }

        else if (_wave == 10)
        {
            std::cout << "boss wave" << std::endl;
            int j = 0;
            while (j < _spawnPoints.size())
            {

                std::cout << "boss sized" << std::endl;
                Enemy enemy;
                _enemies.push_back(std::move(enemy));
                _enemies.back().setSpriteScaleX(3.f);
                _enemies.back().setSpriteScaleY(3.f);
                _enemies.back().getBodySprite().setOrigin(_enemies.back().getBodyTexture().getSize().x * _enemies.back().getSpriteScaleX() / 2.f, _enemies.back().getBodyTexture().getSize().y * _enemies.back().getSpriteScaleY() / 2.f); //set origin
                _enemies.back().getBodySprite().setPosition(_spawnPoints[j].left, _spawnPoints[j].top);

                _enemies.back().setType("boss");
                _enemies.back().isPlaying(true);
                _enemies.back().setBaseAtk(30);
                _enemies.back().setBaseSpeed(0);
                _enemies.back().setBaseMaxHp(300);
                _enemies.back().setBaseXpDrop(200);
                _enemies.back().setBaseMoneyDrop(1000);

                std::cout << "enemy random stats" << std::endl;
                _enemies.back().setColor(sf::Color(0, 0, 0, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                float alpha = static_cast<float>(_enemies.back().getColor().a);
                if (_minAlphaInRange >= 100)
                {
                    std::cout << "nice" << std::endl;
                    _enemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                }
                _enemies.back().setMaxAtk(_enemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _enemies.back().getBaseAtk()) + (1.1 * _enemies.back().getLevel()));
                _enemies.back().setMaxSpeed((alpha / _ultimateAlpha) * 0.20);
                _enemies.back().setMaxHp(_enemies.back().getBaseMaxHp() + (alpha / _ultimateAlpha * _enemies.back().getBaseMaxHp()) + (1.1 * _enemies.back().getLevel()));
                _enemies.back().setHp(_enemies.back().getMaxHp());
                float maxHp = _enemies.back().getMaxHp();
                _enemies.back().setHpLimit(maxHp * 0.20);
                
                std::cout << "atk: " << _enemies.back().getAtk() << std::endl;
                std::cout << "hp: " << _enemies.back().getHp() << std::endl;
                std::cout << "speed: " << _enemies.back().getSpeed() << std::endl;
                std::cout << "reaction time:" << _enemies.back().getReactionTime() << std::endl;

                j++;
            }
        }

        else if (_wave > 10 && _wave <= 19 )
        {
            int j = 0;
            while (j < _spawnPoints.size())
            {
                int rand__ = 0;
                do
                {
                    rand__ = rand() % 100; //100 is arbitrary
                } while (rand__ <= 0);

                if (rand__ > 0 && rand__ <= 68)
                {

                    std::cout << "medium sized" << std::endl;
                    //MEDIUM SIZED ENEMY 
                    Enemy enemy;
                    _enemies.push_back(std::move(enemy));
                    _enemies.back().setSpriteScaleX(1.2f);
                    _enemies.back().setSpriteScaleY(1.3f);
                    _enemies.back().getBodySprite().setOrigin(_enemies.back().getBodyTexture().getSize().x* _enemies.back().getSpriteScaleX() / 2.f, _enemies.back().getBodyTexture().getSize().y* _enemies.back().getSpriteScaleY() / 2.f); //set origin
                    _enemies.back().getBodySprite().setPosition(_spawnPoints[j].left, _spawnPoints[j].top);

                    _enemies.back().setBaseAtk(35);
                    _enemies.back().setBaseSpeed(0);
                    _enemies.back().setBaseMaxHp(80);
                    _enemies.back().setBaseXpDrop(22);
                    _enemies.back().setBaseMoneyDrop(30);

                    std::cout << "enemy random stats" << std::endl;
                    _enemies.back().setColor(sf::Color(0, 0, 0, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                    float alpha = static_cast<float>(_enemies.back().getColor().a);
                    _enemies.back().setMaxAtk(_enemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _enemies.back().getBaseAtk()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setMaxSpeed(1.1 + (alpha / _ultimateAlpha));
                    _enemies.back().setMaxHp(_enemies.back().getBaseMaxHp() + (alpha / _ultimateAlpha * _enemies.back().getBaseMaxHp()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setHp(_enemies.back().getMaxHp());
                    float maxHp = _enemies.back().getMaxHp();
                    _enemies.back().setHpLimit(maxHp / 2);

                    std::cout << "atk: " << _enemies.back().getAtk() << std::endl;
                    std::cout << "hp: " << _enemies.back().getHp() << std::endl;
                    std::cout << "speed: " << _enemies.back().getSpeed() << std::endl;
                }

                else if (rand__ > 68)
                {
                    std::cout << "big sized" << std::endl;
                    //BIG SIZED ENEMY 
                    Enemy enemy;
                    _enemies.push_back(std::move(enemy));
                     _enemies.back().setSpriteScaleX(1.7);
                    _enemies.back().setSpriteScaleY(1.7);
                    _enemies.back().getBodySprite().setOrigin(_enemies.back().getBodyTexture().getSize().x* _enemies.back().getSpriteScaleX() / 2.f, _enemies.back().getBodyTexture().getSize().y* _enemies.back().getSpriteScaleY() / 2.f); //set origin
                    _enemies.back().getBodySprite().setPosition(_spawnPoints[j].left, _spawnPoints[j].top);

                    _enemies.back().setBaseAtk(50);
                    _enemies.back().setBaseSpeed(0);
                    _enemies.back().setBaseMaxHp(95);
                    _enemies.back().setBaseXpDrop(50);
                    _enemies.back().setBaseMoneyDrop(60);

                    std::cout << "enemy random stats" << std::endl;
                    _enemies.back().setColor(sf::Color(0, 0, 0, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                    float alpha = static_cast<float>(_enemies.back().getColor().a);
                    _enemies.back().setMaxAtk(_enemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _enemies.back().getBaseAtk()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setMaxSpeed(1.1 + (alpha / _ultimateAlpha));
                    _enemies.back().setMaxHp(_enemies.back().getBaseMaxHp() + (alpha / _ultimateAlpha * _enemies.back().getBaseMaxHp()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setHp(_enemies.back().getMaxHp());
                    float maxHp = _enemies.back().getMaxHp();
                    _enemies.back().setHpLimit(maxHp / 2);

                    std::cout << "atk: " << _enemies.back().getAtk() << std::endl;
                    std::cout << "hp: " << _enemies.back().getHp() << std::endl;
                    std::cout << "speed: " << _enemies.back().getSpeed() << std::endl;
                }

                j++;
            }

           
        }

        else if (_wave == 20)
        {
            
            std::cout << "boss wave" << std::endl;
            int j = 0;
            while (j < _spawnPoints.size())
            {

                std::cout << "boss sized" << std::endl;
                Enemy enemy;
                _enemies.push_back(std::move(enemy));
                _enemies.back().setSpriteScaleX(3.f);
                _enemies.back().setSpriteScaleY(3.f);
                _enemies.back().getBodySprite().setOrigin(_enemies.back().getBodyTexture().getSize().x* _enemies.back().getSpriteScaleX() / 2.f, _enemies.back().getBodyTexture().getSize().y* _enemies.back().getSpriteScaleY() / 2.f); //set origin
                _enemies.back().getBodySprite().setPosition(_spawnPoints[j].left, _spawnPoints[j].top);

                _enemies.back().setType("boss");
                _enemies.back().isPlaying(true);
                _enemies.back().setBaseAtk(30);
                _enemies.back().setBaseSpeed(0);
                _enemies.back().setBaseMaxHp(300);
                _enemies.back().setBaseXpDrop(200);
                _enemies.back().setBaseMoneyDrop(1000);

                std::cout << "enemy random stats" << std::endl;
                _enemies.back().setColor(sf::Color(0, 0, 0, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                float alpha = static_cast<float>(_enemies.back().getColor().a);
                if (_minAlphaInRange >= 100)
                {
                    std::cout << "nice" << std::endl;
                    _enemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                }
                _enemies.back().setMaxAtk(_enemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _enemies.back().getBaseAtk()) + (1.1 * _enemies.back().getLevel()));
                _enemies.back().setMaxSpeed((alpha / _ultimateAlpha) * 0.20);
                _enemies.back().setMaxHp(_enemies.back().getBaseMaxHp() + (alpha / _ultimateAlpha * _enemies.back().getBaseMaxHp()) + (1.1 * _enemies.back().getLevel()));
                _enemies.back().setHp(_enemies.back().getMaxHp());
                float maxHp = _enemies.back().getMaxHp();
                _enemies.back().setHpLimit(maxHp * 0.20);

                std::cout << "atk: " << _enemies.back().getAtk() << std::endl;
                std::cout << "hp: " << _enemies.back().getHp() << std::endl;
                std::cout << "speed: " << _enemies.back().getSpeed() << std::endl;
                std::cout << "reaction time:" << _enemies.back().getReactionTime() << std::endl;

                j++;
            }

        }

        else if (_wave > 20 && _wave <= 29)
        {
            int j = 0;
            while (j < _spawnPoints.size())
            {
                int rand__ = 0;
                do
                {
                    rand__ = rand() % 100; //100 is arbitrary
                } while (rand__ <= 0);

                if (rand__ > 0 && rand__ <= 75)
                {
                    std::cout << "little sized" << std::endl;
                    Enemy enemy;
                    _enemies.push_back(std::move(enemy));
                    _enemies.back().setSpriteScaleX(1.f);
                    _enemies.back().setSpriteScaleY(1.f);
                    _enemies.back().getBodySprite().setOrigin(_enemies.back().getBodyTexture().getSize().x* _enemies.back().getSpriteScaleX() / 2.f, _enemies.back().getBodyTexture().getSize().y* _enemies.back().getSpriteScaleY() / 2.f); //set origin
                    _enemies.back().getBodySprite().setPosition(_spawnPoints[j].left, _spawnPoints[j].top);

                    _enemies.back().setBaseAtk(15);
                    _enemies.back().setBaseSpeed(0);
                    _enemies.back().setBaseMaxHp(50);
                    _enemies.back().setBaseXpDrop(16.5);
                    _enemies.back().setBaseMoneyDrop(20);

                    std::cout << "enemy random stats" << std::endl;
                    _enemies.back().setColor(sf::Color(0, 0, 0, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                    float alpha = static_cast<float>(_enemies.back().getColor().a);
                    if (_minAlphaInRange >= 100)
                    {
                        std::cout << "nice" << std::endl;
                        _enemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                    }
                    _enemies.back().setMaxAtk(_enemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _enemies.back().getBaseAtk()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setMaxSpeed(1.1 + (alpha / _ultimateAlpha));
                    _enemies.back().setMaxHp(_enemies.back().getBaseMaxHp() + (alpha / _ultimateAlpha * _enemies.back().getBaseMaxHp()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setHp(_enemies.back().getMaxHp());
                    float maxHp = _enemies.back().getMaxHp();
                    _enemies.back().setHpLimit(maxHp / 2);

                    std::cout << "atk: " << _enemies.back().getAtk() << std::endl;
                    std::cout << "hp: " << _enemies.back().getHp() << std::endl;
                    std::cout << "speed: " << _enemies.back().getSpeed() << std::endl;
                    std::cout << "reaction time:" << _enemies.back().getReactionTime() << std::endl;

                }

                else if (rand__ > 75 && rand__ <= 92)
                {
                    std::cout << "medium sized" << std::endl;
                    //MEDIUM SIZED ENEMY 
                    Enemy enemy;
                    _enemies.push_back(std::move(enemy));
                    _enemies.back().setSpriteScaleX(1.2f);
                    _enemies.back().setSpriteScaleY(1.3f);
                    _enemies.back().getBodySprite().setOrigin(_enemies.back().getBodyTexture().getSize().x * _enemies.back().getSpriteScaleX() / 2.f, _enemies.back().getBodyTexture().getSize().y * _enemies.back().getSpriteScaleY() / 2.f); //set origin
                    _enemies.back().getBodySprite().setPosition(_spawnPoints[j].left, _spawnPoints[j].top);

                    _enemies.back().setBaseAtk(35);
                    _enemies.back().setBaseSpeed(0);
                    _enemies.back().setBaseMaxHp(80);
                    _enemies.back().setBaseXpDrop(22);
                    _enemies.back().setBaseMoneyDrop(30);

                    std::cout << "enemy random stats" << std::endl;
                    _enemies.back().setColor(sf::Color(0, 0, 0, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                    float alpha = static_cast<float>(_enemies.back().getColor().a);
                    if (_minAlphaInRange >= 100)
                    {
                        std::cout << "nice" << std::endl;
                        _enemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                    }
                    _enemies.back().setMaxAtk(_enemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _enemies.back().getBaseAtk()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setMaxSpeed(1.1 + (alpha / _ultimateAlpha));
                    _enemies.back().setMaxHp(_enemies.back().getBaseMaxHp() + (alpha / _ultimateAlpha * _enemies.back().getBaseMaxHp()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setHp(_enemies.back().getMaxHp());
                    float maxHp = _enemies.back().getMaxHp();
                    _enemies.back().setHpLimit(maxHp / 2);

                    std::cout << "atk: " << _enemies.back().getAtk() << std::endl;
                    std::cout << "hp: " << _enemies.back().getHp() << std::endl;
                    std::cout << "speed: " << _enemies.back().getSpeed() << std::endl;
                }

                else if (rand__ > 92)
                {
                    std::cout << "big sized" << std::endl;
                    //BIG SIZED ENEMY 
                    Enemy enemy;
                    _enemies.push_back(std::move(enemy));
                    _enemies.back().setSpriteScaleX(1.7);
                    _enemies.back().setSpriteScaleY(1.7);
                    _enemies.back().getBodySprite().setOrigin(_enemies.back().getBodyTexture().getSize().x* _enemies.back().getSpriteScaleX() / 2.f, _enemies.back().getBodyTexture().getSize().y* _enemies.back().getSpriteScaleY() / 2.f); //set origin
                    _enemies.back().getBodySprite().setPosition(_spawnPoints[j].left, _spawnPoints[j].top);

                    _enemies.back().setBaseAtk(50);
                    _enemies.back().setBaseSpeed(0);
                    _enemies.back().setBaseMaxHp(95);
                    _enemies.back().setBaseXpDrop(50);
                    _enemies.back().setBaseMoneyDrop(60);

                    std::cout << "enemy random stats" << std::endl;
                    _enemies.back().setColor(sf::Color(0, 0, 0, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                    float alpha = static_cast<float>(_enemies.back().getColor().a);
                    if (_minAlphaInRange >= 100)
                    {
                        std::cout << "nice" << std::endl;
                        _enemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                    }
                    _enemies.back().setMaxAtk(_enemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _enemies.back().getBaseAtk()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setMaxSpeed(1.1 + (alpha / _ultimateAlpha));
                    _enemies.back().setMaxHp(_enemies.back().getBaseMaxHp() + (alpha / _ultimateAlpha * _enemies.back().getBaseMaxHp()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setHp(_enemies.back().getMaxHp());
                    float maxHp = _enemies.back().getMaxHp();
                    _enemies.back().setHpLimit(maxHp / 2);

                    std::cout << "atk: " << _enemies.back().getAtk() << std::endl;
                    std::cout << "hp: " << _enemies.back().getHp() << std::endl;
                    std::cout << "speed: " << _enemies.back().getSpeed() << std::endl;
                }

                j++;
            }
        } //creating enemies

        else if (_wave == 30)
        {

            std::cout << "boss wave" << std::endl;
            int j = 0;
            while (j < _spawnPoints.size())
            {

                std::cout << "boss sized" << std::endl;
                Enemy enemy;
                _enemies.push_back(std::move(enemy));
                _enemies.back().setSpriteScaleX(3.f);
                _enemies.back().setSpriteScaleY(3.f);
                _enemies.back().getBodySprite().setOrigin(_enemies.back().getBodyTexture().getSize().x* _enemies.back().getSpriteScaleX() / 2.f, _enemies.back().getBodyTexture().getSize().y* _enemies.back().getSpriteScaleY() / 2.f); //set origin
                _enemies.back().getBodySprite().setPosition(_spawnPoints[j].left, _spawnPoints[j].top);

                _enemies.back().setType("boss");
                _enemies.back().isPlaying(true);
                _enemies.back().setBaseAtk(30);
                _enemies.back().setBaseSpeed(0);
                _enemies.back().setBaseMaxHp(300);
                _enemies.back().setBaseXpDrop(200);
                _enemies.back().setBaseMoneyDrop(1000);

                std::cout << "enemy random stats" << std::endl;
                _enemies.back().setColor(sf::Color(0, 0, 0, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                float alpha = static_cast<float>(_enemies.back().getColor().a);
                if (_minAlphaInRange >= 100)
                {
                    std::cout << "nice" << std::endl;
                    _enemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                }
                _enemies.back().setMaxAtk(_enemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _enemies.back().getBaseAtk()) + (1.1 * _enemies.back().getLevel()));
                _enemies.back().setMaxSpeed((alpha / _ultimateAlpha) * 0.20);
                _enemies.back().setMaxHp(_enemies.back().getBaseMaxHp() + (alpha / _ultimateAlpha * _enemies.back().getBaseMaxHp()) + (1.1 * _enemies.back().getLevel()));
                _enemies.back().setHp(_enemies.back().getMaxHp());
                float maxHp = _enemies.back().getMaxHp();
                _enemies.back().setHpLimit(maxHp * 0.20);

                std::cout << "atk: " << _enemies.back().getAtk() << std::endl;
                std::cout << "hp: " << _enemies.back().getHp() << std::endl;
                std::cout << "speed: " << _enemies.back().getSpeed() << std::endl;
                std::cout << "reaction time:" << _enemies.back().getReactionTime() << std::endl;

                j++;
            }

        }

        else if (_wave > 30 && _wave <= 39)
        {
            int j = 0;
            while (j < _spawnPoints.size())
            {
                int rand__ = 0;
                do
                {
                    rand__ = rand() % 100; //100 is arbitrary
                } while (rand__ <= 0);

                if (rand__ > 0 && rand__ <= 75)
                {
                    std::cout << "big sized" << std::endl;
                    //BIG SIZED ENEMY 
                    Enemy enemy;
                    _enemies.push_back(std::move(enemy));
                    _enemies.back().setSpriteScaleX(1.7);
                    _enemies.back().setSpriteScaleY(1.7);
                    _enemies.back().getBodySprite().setOrigin(_enemies.back().getBodyTexture().getSize().x* _enemies.back().getSpriteScaleX() / 2.f, _enemies.back().getBodyTexture().getSize().y* _enemies.back().getSpriteScaleY() / 2.f); //set origin
                    _enemies.back().getBodySprite().setPosition(_spawnPoints[j].left, _spawnPoints[j].top);

                    _enemies.back().setBaseAtk(50);
                    _enemies.back().setBaseSpeed(0);
                    _enemies.back().setBaseMaxHp(95);
                    _enemies.back().setBaseXpDrop(50);
                    _enemies.back().setBaseMoneyDrop(60);

                    std::cout << "enemy random stats" << std::endl;
                    _enemies.back().setColor(sf::Color(0, 0, 0, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                    float alpha = static_cast<float>(_enemies.back().getColor().a);
                    if (_minAlphaInRange >= 100)
                    {
                        std::cout << "nice" << std::endl;
                        _enemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                    }
                    _enemies.back().setMaxAtk(_enemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _enemies.back().getBaseAtk()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setMaxSpeed(1.1 + (alpha / _ultimateAlpha));
                    _enemies.back().setMaxHp(_enemies.back().getBaseMaxHp() + (alpha / _ultimateAlpha * _enemies.back().getBaseMaxHp()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setHp(_enemies.back().getMaxHp());
                    float maxHp = _enemies.back().getMaxHp();
                    _enemies.back().setHpLimit(maxHp / 2);

                    std::cout << "atk: " << _enemies.back().getAtk() << std::endl;
                    std::cout << "hp: " << _enemies.back().getHp() << std::endl;
                    std::cout << "speed: " << _enemies.back().getSpeed() << std::endl;
                }

                else if (rand__ > 75 && rand__ <= 92)
                {
                    std::cout << "medium sized" << std::endl;
                    //MEDIUM SIZED ENEMY 
                    Enemy enemy;
                    _enemies.push_back(std::move(enemy));
                    _enemies.back().setSpriteScaleX(1.2f);
                    _enemies.back().setSpriteScaleY(1.3f);
                    _enemies.back().getBodySprite().setOrigin(_enemies.back().getBodyTexture().getSize().x * _enemies.back().getSpriteScaleX() / 2.f, _enemies.back().getBodyTexture().getSize().y * _enemies.back().getSpriteScaleY() / 2.f); //set origin
                    _enemies.back().getBodySprite().setPosition(_spawnPoints[j].left, _spawnPoints[j].top);

                    _enemies.back().setBaseAtk(35);
                    _enemies.back().setBaseSpeed(0);
                    _enemies.back().setBaseMaxHp(80);
                    _enemies.back().setBaseXpDrop(22);
                    _enemies.back().setBaseMoneyDrop(30);

                    std::cout << "enemy random stats" << std::endl;
                    _enemies.back().setColor(sf::Color(0, 0, 0, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                    float alpha = static_cast<float>(_enemies.back().getColor().a);
                    if (_minAlphaInRange >= 100)
                    {
                        std::cout << "nice" << std::endl;
                        _enemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                    }
                    _enemies.back().setMaxAtk(_enemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _enemies.back().getBaseAtk()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setMaxSpeed(1.1 + (alpha / _ultimateAlpha));
                    _enemies.back().setMaxHp(_enemies.back().getBaseMaxHp() + (alpha / _ultimateAlpha * _enemies.back().getBaseMaxHp()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setHp(_enemies.back().getMaxHp());
                    float maxHp = _enemies.back().getMaxHp();
                    _enemies.back().setHpLimit(maxHp / 2);

                    std::cout << "atk: " << _enemies.back().getAtk() << std::endl;
                    std::cout << "hp: " << _enemies.back().getHp() << std::endl;
                    std::cout << "speed: " << _enemies.back().getSpeed() << std::endl;
                }

                else if (rand__ > 92)
                {
                    std::cout << "little sized" << std::endl;
                    Enemy enemy;
                    _enemies.push_back(std::move(enemy));
                    _enemies.back().setSpriteScaleX(1.f);
                    _enemies.back().setSpriteScaleY(1.f);
                    _enemies.back().getBodySprite().setOrigin(_enemies.back().getBodyTexture().getSize().x* _enemies.back().getSpriteScaleX() / 2.f, _enemies.back().getBodyTexture().getSize().y* _enemies.back().getSpriteScaleY() / 2.f); //set origin
                    _enemies.back().getBodySprite().setPosition(_spawnPoints[j].left, _spawnPoints[j].top);

                    _enemies.back().setBaseAtk(15);
                    _enemies.back().setBaseSpeed(0);
                    _enemies.back().setBaseMaxHp(50);
                    _enemies.back().setBaseXpDrop(16.5);
                    _enemies.back().setBaseMoneyDrop(20);

                    std::cout << "enemy random stats" << std::endl;
                    _enemies.back().setColor(sf::Color(0, 0, 0, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                    float alpha = static_cast<float>(_enemies.back().getColor().a);
                    if (_minAlphaInRange >= 100)
                    {
                        std::cout << "nice" << std::endl;
                        _enemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                    }
                    _enemies.back().setMaxAtk(_enemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _enemies.back().getBaseAtk()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setMaxSpeed(1.1 + (alpha / _ultimateAlpha));
                    _enemies.back().setMaxHp(_enemies.back().getBaseMaxHp() + (alpha / _ultimateAlpha * _enemies.back().getBaseMaxHp()) + (1.1 * _enemies.back().getLevel()));
                    _enemies.back().setHp(_enemies.back().getMaxHp());
                    float maxHp = _enemies.back().getMaxHp();
                    _enemies.back().setHpLimit(maxHp / 2);

                    std::cout << "atk: " << _enemies.back().getAtk() << std::endl;
                    std::cout << "hp: " << _enemies.back().getHp() << std::endl;
                    std::cout << "speed: " << _enemies.back().getSpeed() << std::endl;
                    std::cout << "reaction time:" << _enemies.back().getReactionTime() << std::endl;
                }

                j++;
            }
        }

        else if (_wave == 40)
        {

            std::cout << "boss wave" << std::endl;
            int j = 0;
            while (j < _spawnPoints.size())
            {

                std::cout << "boss sized" << std::endl;
                Enemy enemy;
                _enemies.push_back(std::move(enemy));
                _enemies.back().setSpriteScaleX(3.f);
                _enemies.back().setSpriteScaleY(3.f);
                _enemies.back().getBodySprite().setOrigin(_enemies.back().getBodyTexture().getSize().x* _enemies.back().getSpriteScaleX() / 2.f, _enemies.back().getBodyTexture().getSize().y* _enemies.back().getSpriteScaleY() / 2.f); //set origin
                _enemies.back().getBodySprite().setPosition(_spawnPoints[j].left, _spawnPoints[j].top);

                _enemies.back().setType("boss");
                _enemies.back().isPlaying(true);
                _enemies.back().setBaseAtk(30);
                _enemies.back().setBaseSpeed(0);
                _enemies.back().setBaseMaxHp(300);
                _enemies.back().setBaseXpDrop(200);
                _enemies.back().setBaseMoneyDrop(1000);

                std::cout << "enemy random stats" << std::endl;
                _enemies.back().setColor(sf::Color(0, 0, 0, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                float alpha = static_cast<float>(_enemies.back().getColor().a);
                if (_minAlphaInRange >= 100)
                {
                    std::cout << "nice" << std::endl;
                    _enemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
                }
                _enemies.back().setMaxAtk(_enemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _enemies.back().getBaseAtk()) + (1.1 * _enemies.back().getLevel()));
                _enemies.back().setMaxSpeed((alpha / _ultimateAlpha) * 0.20);
                _enemies.back().setMaxHp(_enemies.back().getBaseMaxHp() + (alpha / _ultimateAlpha * _enemies.back().getBaseMaxHp()) + (1.1 * _enemies.back().getLevel()));
                _enemies.back().setHp(_enemies.back().getMaxHp());
                float maxHp = _enemies.back().getMaxHp();
                _enemies.back().setHpLimit(maxHp * 0.20);

                std::cout << "atk: " << _enemies.back().getAtk() << std::endl;
                std::cout << "hp: " << _enemies.back().getHp() << std::endl;
                std::cout << "speed: " << _enemies.back().getSpeed() << std::endl;
                std::cout << "reaction time:" << _enemies.back().getReactionTime() << std::endl;

                j++;
            }

        }
       
		for (auto& enemy : _enemies)
		{
            enemy.getLevelText().setFont(_fontForTextLevel);
            enemy.getLevelText().setFillColor(sf::Color::White);
            enemy.getLevelText().setOutlineColor(enemy.getColor());
            enemy.getLevelText().setOutlineThickness(3);
            enemy.getLevelText().setStyle(sf::Text::Bold);

			enemy.getBodyTexture().loadFromFile("data/Enemy/body.png");
            enemy.getBodySprite().setTexture(enemy.getBodyTexture());
            enemy.getBodySprite().setOrigin(enemy.getBodyTexture().getSize().x * enemy.getSpriteScaleX() / 2.f,enemy.getBodyTexture().getSize().y * enemy.getSpriteScaleY() / 2.f);

            enemy.getLeftWingTexture().loadFromFile("data/Enemy/leftWing.png");
            enemy.getLeftWingSprite().setTexture(enemy.getLeftWingTexture());
            enemy.getLeftWingSprite().setOrigin(enemy.getLeftWingTexture().getSize().x * enemy.getSpriteScaleX() / 2.f,enemy.getLeftWingTexture().getSize().y * enemy.getSpriteScaleY() / 2.f);

            enemy.getRightWingTexture().loadFromFile("data/Enemy/rightWing.png");
            enemy.getRightWingSprite().setTexture(enemy.getRightWingTexture());
            enemy.getRightWingSprite().setOrigin(enemy.getRightWingTexture().getSize().x * enemy.getSpriteScaleX() / 2.f,enemy.getRightWingTexture().getSize().y * enemy.getSpriteScaleY() / 2.f);

            enemy.getTailTexture().loadFromFile("data/Enemy/tail.png");
            enemy.getTailSprite().setTexture(enemy.getTailTexture());
            enemy.getTailSprite().setOrigin(enemy.getTailTexture().getSize().x * enemy.getSpriteScaleX() / 2.f,enemy.getTailTexture().getSize().y * enemy.getSpriteScaleY() / 2.f);

            float widthOfEnemyBody = enemy.getBodyTexture().getSize().x * enemy.getSpriteScaleX();
            float heightOfEnemyBody = enemy.getBodyTexture().getSize().y * enemy.getSpriteScaleY();

            float widthOfEnemyLeftWing = enemy.getLeftWingTexture().getSize().x * enemy.getSpriteScaleX();
            float widthOfEnemyRightWing = enemy.getRightWingTexture().getSize().x * enemy.getSpriteScaleX();
           
            enemy.getBodySprite().setPosition(enemy.getBodySprite().getPosition().x - widthOfEnemyBody / 2.f - widthOfEnemyRightWing, enemy.getBodySprite().getPosition().y + heightOfEnemyBody / 1.4f);
            
		}

        _nbEnemies = _enemies.size();
    }
    void Game::initHealthBarsOfEnemies()
    {
        /*_healthBarEnemy.getHealthBarTexture().loadFromFile("data/Enemy/healthBar.png");
        _healthBarEnemy.getHealthBarSprite().setTexture(_healthBarEnemy.getHealthBarTexture());
        _healthBarEnemy.getHealthBarSprite().setOrigin(_healthBarEnemy.getHealthBarSprite().getTexture()->getSize().x / 2.f
            , _healthBarEnemy.getHealthBarSprite().getTexture()->getSize().y / 2.f);

        _healthBarEnemy.getHoverTexture().loadFromFile("data/Enemy/healthBar.png");
        _healthBarEnemy.getHoverSprite().setTexture(_healthBarEnemy.getHoverTexture());
        _healthBarEnemy.getHoverSprite().setOrigin(_healthBarEnemy.getHealthBarSprite().getTexture()->getSize().x / 2.f
            , _healthBarEnemy.getHoverSprite().getTexture()->getSize().y / 2.f);
        
        float maxWidthHealthBar = _healthBarEnemy.getHealthBarSprite().getScale().x *
            _healthBarEnemy.getHealthBarTexture().getSize().x;

        float newWidthHealthBar = _enemy.getBodyTexture().getSize().x * _enemy.getSpriteScaleX() + 6.f * _enemy.getSpriteScaleX();
		
        _healthBarEnemy.getHealthBarSprite().setScale(newWidthHealthBar
            / maxWidthHealthBar, 1.f);
            */
        int i = 50;
        int nbEnemyHealthbars = 0;

		//I create an healthBar for every enemy
		for (auto& enemy : _enemies)
		{
			enemy.setHealthPtr(&enemy.getHealth());
            //enemy.getDamage(i)
            enemy.getHealthBarEmpty().setSize(sf::Vector2f(92, 15));
            float standardwidthHealthbar = enemy.getHealthBarEmpty().getSize().x *
                enemy.getHealthBarEmpty().getScale().x;
            float standardHeightHealthbar = enemy.getHealthBarEmpty().getSize().y * 
                enemy.getHealthBarEmpty().getScale().y;
            enemy.getHealthBarEmpty().setOrigin(standardwidthHealthbar / 2, standardHeightHealthbar / 2);
            enemy.getHealthBarEmpty().setOutlineThickness(-1);
            enemy.getHealthBarEmpty().setOutlineColor(sf::Color::Black);
			enemy.getHealthBarEmpty().setPosition(-500, -500);

            enemy.getHealthbar().setSize(sf::Vector2f(standardwidthHealthbar, standardHeightHealthbar));
            enemy.getHealthbar().setOrigin(standardwidthHealthbar / 2, standardHeightHealthbar / 2);
            enemy.getHealthbar().setPosition(-500, -500);

            float maxWidthHealthBar = enemy.getHealthBarEmpty().getSize().x * enemy.getHealthBarEmpty().getScale().x;
            float newWidthHealthBar = enemy.getBodyTexture().getSize().x * enemy.getSpriteScaleX() + 6.f * enemy.getSpriteScaleX();

            enemy.getHealthBarEmpty().setScale(newWidthHealthBar
                / maxWidthHealthBar, 1.f);

            enemy.getHealthbar().setScale(enemy.getHealthBarEmpty().getScale());
            enemy.getHealthbar().setFillColor(enemy.getColor());
            i++;
            nbEnemyHealthbars++;
            std::cout << "we have " << nbEnemyHealthbars << " healthbars of enemies" << std::endl;
		}

	    /*for (auto& enemy : _enemies)
	    {
            enemy.getHealthPtr()->getObserversList().back()->setHealthPtr(enemy.getHealthPtr());
	    }
	    */
		//test -> it shows evidence that every  healtbars of
		//"std::vector<HealthObserver> _healthBarsOfEnemies" is attached to one enemy (good)
		
    }

    void Game::initReactionTimeBarsOfEnemies()
    {
        for (auto& enemy : _enemies)
        {

            enemy.getReactionTimeBarEmpty().setSize(sf::Vector2f(92, 15));
            float standardwidthReactionTimeBar = enemy.getReactionTimeBarEmpty().getSize().x *
                enemy.getReactionTimeBarEmpty().getScale().x;
            float standardHeightReactionTimeBar = enemy.getReactionTimeBarEmpty().getSize().y *
                enemy.getReactionTimeBarEmpty().getScale().y;
            enemy.getReactionTimeBarEmpty().setOrigin(standardwidthReactionTimeBar / 2, standardHeightReactionTimeBar / 2);
            enemy.getReactionTimeBarEmpty().setOutlineThickness(-1);
            enemy.getReactionTimeBarEmpty().setOutlineColor(sf::Color::Black);
            enemy.getReactionTimeBarEmpty().setPosition(100, 100);

            enemy.getReactionTimeBar().setSize(sf::Vector2f(standardwidthReactionTimeBar, standardHeightReactionTimeBar));
            enemy.getReactionTimeBar().setOrigin(standardwidthReactionTimeBar / 2, standardHeightReactionTimeBar / 2);
            enemy.getReactionTimeBar().setPosition(-500, -500);

            float maxWidthReactionTimeBar = enemy.getReactionTimeBarEmpty().getSize().x * enemy.getReactionTimeBarEmpty().getScale().x;
            float newWidthReactionTimeBar = enemy.getBodyTexture().getSize().x * enemy.getSpriteScaleX() + 6.f * enemy.getSpriteScaleX();

            enemy.getReactionTimeBarEmpty().setScale(newWidthReactionTimeBar
                / maxWidthReactionTimeBar, 1.f);

            enemy.getReactionTimeBar().setScale(enemy.getReactionTimeBarEmpty().getScale());
            enemy.getReactionTimeBar().setFillColor(sf::Color(54,44,252));
        }   
    }


void Game::run()
{

    //_player.getDamage(10);
    //std::cout << "player hp: " << _healthBarPlayer.getDamageablePtr()->getHealth().getHp() << std::endl;
    while (_settings.getGameWindow().isOpen())
    {
        sf::Clock clock;
        clock.restart();

        getInputs();
       
        if (!_pause)
        {
           update();
        }


      
   
        render();

        totalTimeElapsed += clock.getElapsedTime().asMilliseconds();
        _timerLevelUp += clock.getElapsedTime().asMilliseconds();
        _timerDictacticiel += clock.getElapsedTime().asMilliseconds();
        //std::cout << "time elapsed since last frame (ms): " << clock.getElapsedTime().asMilliseconds() << std::endl;

    }
}

	void Game::getInputs()
{
    
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;

    while (_settings.getGameWindow().pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
        {
           _settings.getGameWindow().close();
        }
        getPlayerInputs(event);
    }

}
		void Game::getPlayerInputs(sf::Event& event)
		{
            
            float x = sf::Mouse::getPosition(_settings.getGameWindow()).x;
            float y = sf::Mouse::getPosition(_settings.getGameWindow()).y;

			//MOVEMENTS INPUTS
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Key::Z)
                {
                    for (auto& player : _playerStorer)
                    {
                        float heightOfPlayer = player.getTexture().getSize().y;
                        if ((player.getSprite().getPosition().y - heightOfPlayer / 2.f) - (_settings.getBattleAreaBorders().getPosition().y - _outlineThickness) > 0.f)
                        {
                            player.isGoingUp(true);
                        }


                        else
                        {
                            float d = (player.getSprite().getPosition().y - heightOfPlayer / 2.f) - (_settings.getBattleAreaBorders().getPosition().y - _outlineThickness);
                            player.move(0.f, -d);
                            player.isGoingUp(false);
                        }
                    }
                    
                }

                if (event.key.code == sf::Keyboard::Key::Q)
                {
                    for (auto& player: _playerStorer)
                    {
                        float widthOfPlayer = player.getTexture().getSize().x;
                        if ((player.getSprite().getPosition().x - widthOfPlayer / 2.f) - (_settings.getBattleAreaBorders().getPosition().x - _outlineThickness) > 0.f)
                        {
                            player.isGoingLeft(true);
                        }


                        else
                        {
                            float d = (player.getSprite().getPosition().x - widthOfPlayer / 2.f) - (_settings.getBattleAreaBorders().getPosition().x - _outlineThickness);
                            player.move(-d, 0.f);
                            player.isGoingLeft(false);
                        }
                    }
                   
                }

                if (event.key.code == sf::Keyboard::Key::S)
                {
                    for (auto& player : _playerStorer)
                    {
                        float heightOfPlayer = player.getTexture().getSize().y;
                        float heightOfBattleAreraBorders = _settings.getBattleAreaBorders().getSize().y + (2 * _outlineThickness);
                        if ((player.getSprite().getPosition().y + heightOfPlayer / 2.f) - (_settings.getBattleAreaBorders().getPosition().y - _outlineThickness + heightOfBattleAreraBorders) < 0.f)
                        {
                            player.isGoingDown(true);
                        }


                        else
                        {
                            float d = (player.getSprite().getPosition().y + heightOfPlayer / 2.f) - (_settings.getBattleAreaBorders().getPosition().y - _outlineThickness + heightOfBattleAreraBorders);
                            player.move(0.f, -d);
                            player.isGoingDown(false);
                        }
                    }

                }

                if (event.key.code == sf::Keyboard::Key::D)
                {
                    for (auto& player : _playerStorer)
                    {
                        float widthOfPlayer = player.getTexture().getSize().x;
                        float widthOfBattleAreraBorders = _settings.getBattleAreaBorders().getSize().x + (2 * _outlineThickness);
                        if ((player.getSprite().getPosition().x + widthOfPlayer / 2.f) - (_settings.getBattleAreaBorders().getPosition().x - _outlineThickness + widthOfBattleAreraBorders) < 0.f)
                        {
                            player.isGoingRight(true);
                        }


                        else
                        {
                            float d = (player.getSprite().getPosition().x + widthOfPlayer / 2.f) - (_settings.getBattleAreaBorders().getPosition().x - _outlineThickness + widthOfBattleAreraBorders);
                            player.move(-d, 0.f);
                            player.isGoingRight(false);
                        }
                    }
                }

                if(event.key.code == sf::Keyboard::Key::Space)
                {
                    for (auto& player : _playerStorer)
                    {
                        player.getSprite().setRotation(player.getRotationOfBasicAttack());
                        player.isAttacking(true);
                    }
                }

                if (event.key.code == sf::Keyboard::A)
                {
                    for (auto& player : _playerStorer)
                    {
                        std::cout << player.getXpToLevelUp() << std::endl;
                    }
                    if (!_gameOver)
                    {
                   
                        if (_nbEnemies <= 0)
                        {                 
                           
                            _ball.setCurrentSpeed(_ball.getBaseSpeed());
                            _ball.setCollisionWithPlayer(false);
                            _ball.setCollisionWithPlayerCamp(false);
                            _ball.setCollisionWithEnemy(false);
                            _ball.setCollisionWithEnemyCamp(false);
                            _ball.isGoingLeft(false);
                            _ball.isGoingRight(false);
                            _ball.isGoingUp(false);
                            _ball.isGoingDown(false);

                            _startingPhase = true;
                            
                            _upgradePhase = false;
                            _playerHasLeveledUp = false;
                            _wave++;
                            
                            
                            _minAlphaInRange += 5;
                            _maxAlphaInRange += 5;
                            std::cout << _minEnemies << std::endl;
                            std::cout << _maxEnemies << std::endl;
                            _waveText.setString("WAVE " + std::to_string(_wave));
                          
                           
                            //std::cout << "wave: " << _wave << std::endl << std::endl;
                            if (_maxAlphaInRange >= 254)
                            {
                                _maxAlphaInRange = 254;
                            }
                            _spawnPoints.erase(_spawnPoints.begin(), _spawnPoints.end());
                            _enemies.erase(_enemies.begin(), _enemies.end());


                            if (_wave % 5 == 0 && _wave != 0)
                            {
                                std::cout << "wave modulo 5" << std::endl;
                                _minEnemies++;
                                _maxEnemies++;
                                if (_maxEnemies >= 6)
                                {
                                    _maxEnemies = 6;
                                }
                                if (_minEnemies >= 5)
                                {
                                    _minEnemies = 2;
                                }

                                initEnemies();
                                initHealthBarsOfEnemies();
                                initReactionTimeBarsOfEnemies();
                                Enemy::levelUp();
                                for (auto& enemy : _enemies)
                                {

                                    enemy.boost();
                                    std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                    std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                    std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;
                                } //spawn wave
                            }

                            if (_wave % 10 == 0 && _wave !=0)
                            {
                                
                                for (auto& enemy : _enemies)
                                {
                                    enemy.boost();
                                    std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                    std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                    std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;
                                } //spawn boss wave


                            }

                            
                            else if (_wave > 5 && _wave <= 9)
                            {

                                initEnemies();
                                initHealthBarsOfEnemies();
                                initReactionTimeBarsOfEnemies();
                                std::cout << "les ennemies rigolent plus!" << std::endl;
                                for (auto& enemy : _enemies)
                                {

                                    enemy.boost();
                                    std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                    std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                    std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;

                                }

                            } //spawn wave

                            else if (_wave > 10 && _wave <= 14)
                            {

                                initEnemies();
                                initHealthBarsOfEnemies();
                                initReactionTimeBarsOfEnemies();
                                std::cout << "les ennemies rigolent plus!" << std::endl;
                                for (auto& enemy : _enemies)
                                {

                                    enemy.boost();
                                    std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                    std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                    std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;

                                }

                            } //spawn wave

                            else if (_wave > 15 && _wave <= 19)
                            {

                                initEnemies();
                                initHealthBarsOfEnemies();
                                initReactionTimeBarsOfEnemies();
                                std::cout << "les ennemies rigolent plus!" << std::endl;
                                for (auto& enemy : _enemies)
                                {

                                    enemy.boost();
                                    std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                    std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                    std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;

                                }

                            } //spawn wave

                            else if (_wave > 20 && _wave <= 24)
                            {

                                initEnemies();
                                initHealthBarsOfEnemies();
                                initReactionTimeBarsOfEnemies();
                                std::cout << "les ennemies rigolent plus!" << std::endl;
                                for (auto& enemy : _enemies)
                                {

                                    enemy.boost();
                                    std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                    std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                    std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;

                                }

                            } //spawn wave

                            else if (_wave > 25 && _wave <= 29)
                            {

                                initEnemies();
                                initHealthBarsOfEnemies();
                                initReactionTimeBarsOfEnemies();
                                std::cout << "les ennemies rigolent plus!" << std::endl;
                                for (auto& enemy : _enemies)
                                {

                                    enemy.boost();
                                    std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                    std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                    std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;

                                }

                            } //spawn wave

                            else if (_wave > 30 && _wave <= 34)
                            {
                                initEnemies();
                                initHealthBarsOfEnemies();
                                initReactionTimeBarsOfEnemies();
                                std::cout << "les ennemies rigolent plus!" << std::endl;
                                for (auto& enemy : _enemies)
                                {

                                    enemy.boost();
                                    std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                    std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                    std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;

                                }

                            } //spawn wave

                            else if (_wave > 35 && _wave <= 39)
                            {
                                initEnemies();
                                initHealthBarsOfEnemies();
                                initReactionTimeBarsOfEnemies();
                                std::cout << "les ennemies rigolent plus!" << std::endl;
                                for (auto& enemy : _enemies)
                                {

                                    enemy.boost();
                                    std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                    std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                    std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;

                                }

                            } //spawn wave
                            
                            else if(_wave > 0 && _wave <= 4)
                            {
                                std::cout << "wave 1 - 4" << std::endl;
                                initEnemies();
                                initHealthBarsOfEnemies();
                                initReactionTimeBarsOfEnemies();
                            }///spawn wave

                            std::cout << _maxEnemies << std::endl;
                        }
                    }
                   

                }

                if (event.key.code == sf::Keyboard::Key::Num1)
                {
                    float x = sf::Mouse::getPosition(_settings.getGameWindow()).x;
                    float y = sf::Mouse::getPosition(_settings.getGameWindow()).y;
                    if (_money >= _blocsInStore.front().getPrice())
                    {
                        Bloc bloc;
                        bloc.getCollider().setFillColor(_blocsInStore.front().getCollider().getFillColor());
                        bloc.getCollider().setPosition(x, y);
                        _blocsInBattle.push_back(std::move(bloc));
                        _money -= _blocsInStore.front().getPrice();
                    }
                    
                }

                if (event.key.code == sf::Keyboard::Key::Num2)
                {
                    float x = sf::Mouse::getPosition(_settings.getGameWindow()).x;
                    float y = sf::Mouse::getPosition(_settings.getGameWindow()).y;
                    
                    for (auto& blocInStore : _blocsInStore)
                    {
                        if (blocInStore.getId() == 2)
                        {
                            if (_money >= blocInStore.getPrice())
                            {
                                Bloc bloc;
                                bloc.getCollider().setFillColor(blocInStore.getCollider().getFillColor());
                                bloc.getCollider().setPosition(x, y);
                                _blocsInBattle.push_back(std::move(bloc));
                                _money -= blocInStore.getPrice();
                            }
                           
                        }
                    }
                    
                }


            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Key::Z)
                {

                    for (auto& player : _playerStorer)
                    {
                        player.isGoingUp(false);
                    }
                   
                }

                if (event.key.code == sf::Keyboard::Key::Q)
                {
                    for (auto& player : _playerStorer)
                    {
                        player.isGoingLeft(false);
                    }
                }

                if (event.key.code == sf::Keyboard::Key::S)
                {
                    for (auto& player : _playerStorer)
                    {
                        player.isGoingDown(false);
                    }
                }

                if (event.key.code == sf::Keyboard::Key::D)
                {
                    for (auto& player : _playerStorer)
                    {
                        player.isGoingRight(false);
                    }
                }

                if (event.key.code == sf::Keyboard::Key::Space)
                {
                    for (auto& player : _playerStorer)
                    {
                        player.getSprite().setRotation(0.f);
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    
                    _spriteOfWelcomeScreen.setPosition(-1000, -1000);
                    float widthBattleArea = _settings.getWidthOfBattleAreaBorders();
                    float heighBattleArea = _settings.getHeightOfBattleAreaBorders();
                    float battleAreaX = _settings.getBattleAreaBorders().getPosition().x;
                    float battleAreaY = _settings.getBattleAreaBorders().getPosition().y;
                   
                    if (_explanationBallHitEnemy)
                    {
                        _explanationBallHitEnemySeen = true;
                        _textOfExplanationBallHitEnemy.setPosition(-1000, -1000);
                        _theGreenZoneText.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.3);
                        _playerCampDescription.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.22);
                    }

                    if (_explanationBallHitPlayer)
                    {
                        _explanationBallHitPlayerSeen = true;
                        _textOfExplanationBallHitPlayer.setPosition(-1000, -1000);
                        _theDefendingWallText.setPosition(-1000, -1000);
                        _theGreenZoneText.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.3);
                        _playerCampDescription.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.22);
 

                    }

                    if (_explanationBallHitDefendingWall)
                    {
                        _explanationBallHitDefendingWallSeen = true;
                        _textOfExplanationBallHitDefendingWall.setPosition(-1000, -1000);
                        _theDefendingWallText.setPosition(-1000, -1000);
                        _theGreenZoneText.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.3);
                        _playerCampDescription.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.22);
                    }

                    if (_explanationBallHitEnemyCamp)
                    {
                        _explanationBallHitEnemyCampSeen = true;
                        _textOfExplanationBallHitEnemyCamp.setPosition(-1000, -1000);
                        _theRedZoneText.setPosition(-1000, -1000);
                        _theGreenZoneText.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.3);
                        _playerCampDescription.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.22);
                    }

                    if (_explanationBallHitPlayerCamp)
                    {
                        _explanationBallHitPlayerCampSeen = true;
                        _textOfExplanationBallHitPlayerCamp.setPosition(-1000, -1000);
                        _theGreenZoneText.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.3);
                        _playerCampDescription.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.22);
                    }

                    if (_explanationBallHitPlayerCamp2)
                    {
                        _explanationBallHitPlayerCampSeen2 = true;
                        _textOfExplanationBallHitPlayerCamp2.setPosition(-1000, -1000);
                        _theGreenZoneText.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.3);
                        _playerCampDescription.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.22);
                       
                    }

                    if (_explanationPlayerImmune)
                    {
                        _explanationPlayerImmuneSeen = true;
                        _textOfExplanationPlayerImmune.setPosition(-1000, -1000);
                        _theGreenZoneText.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.3);
                        _playerCampDescription.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.22);
                    }


                    if (_explanationEnemiesTargetingPlayer)
                    {
                        _explanationEnemiesTargetingPlayerSeen = true;
                        _textOfExplanationEnemiesTargetingPlayer.setPosition(-1000, -1000);
                        _theGreenZoneText.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.3);
                        _playerCampDescription.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.22);
                    }

                    if (_explanationReactionSpeedEnemy)
                    {
                        _explanationReactionSpeedEnemySeen = true;
                        _spriteOfExplanationReactionSpeedEnemy.setPosition(-1000, -1000);
                        _theGreenZoneText.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.3);
                        _playerCampDescription.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.22);
                    }

                    if (_explanationBallHitEnemySeen
                        && _explanationBallHitPlayerSeen
                        && _explanationBallHitDefendingWallSeen
                        && _explanationBallHitEnemyCampSeen
                        && _explanationBallHitPlayerCampSeen
                        && _explanationBallHitPlayerCampSeen2
                        && _explanationPlayerImmuneSeen
                        && _explanationEnemiesTargetingPlayerSeen
                        && _explanationReactionSpeedEnemySeen)
                    {
                        if (_spriteOfPlayButton.getGlobalBounds().contains(x, y))
                        {
                            _upgradePhase = true;
                            _spriteOfPlayButton.setPosition(-1000, -1000);
                            _spawnPoints.erase(_spawnPoints.begin(), _spawnPoints.end());
                            _enemies.erase(_enemies.begin(), _enemies.end());
                            _nbEnemies = 0;
                        }
                    }



                    if (_upgradePhase)
                    {
                        float widthHealItemBox = _textureOfHealItem.getSize().x;
                        float heightHealItemBox = _textureOfHealItem.getSize().y;
                        float healItemX = _spriteOfHealItem.getPosition().x;
                        float healItemY = _spriteOfHealItem.getPosition().y;
                        sf::FloatRect healItemBox(healItemX - widthHealItemBox / 2, healItemY - heightHealItemBox / 2, widthHealItemBox, heightHealItemBox);
                        if (healItemBox.contains(x, y))
                        {
                            if (_money >= _priceHealItem)
                            {
                                for (auto& player : _playerStorer)
                                {
                                    player.setHp(player.getHp() + (0.3 * player.getMaxHp()));
                                    if (player.getHp() >= player.getMaxHp())
                                    {
                                        player.setHp(player.getMaxHp());
                                    }
                                    _money -= _priceHealItem;
                                    _moneySpentEffectSound.play();
                                }
                            }

                        }


                        float widthReductionDamageItemBox = _textureOfReductionDamageItem.getSize().x;
                        float heightReductionDamageItemBox = _textureOfReductionDamageItem.getSize().y;
                        float ReductionDamageItemX = _spriteOfReductionDamageItem.getPosition().x;
                        float ReductionDamageItemY = _spriteOfReductionDamageItem.getPosition().y;
                        sf::FloatRect ReductionDamageItemBox(ReductionDamageItemX - widthReductionDamageItemBox / 2, ReductionDamageItemY - heightReductionDamageItemBox / 2, widthReductionDamageItemBox, heightReductionDamageItemBox);
                        if (ReductionDamageItemBox.contains(x, y))
                        {
                            if (_money >= _priceReductionDamageItem)
                            {
                                for (auto& player : _playerStorer)
                                {
                                    _reductionDamageIsUnlocked = true;
                                    _money -= _priceReductionDamageItem;
                                    _moneySpentEffectSound.play();
                                }
                            }

                        }


                        /*float widthdefendingWallItemBox = _textureOfDefendingWallItem.getSize().x;
                        float heightdefendingWallItemBox = _textureOfDefendingWallItem.getSize().y;
                        float defendingWallItemX = _spriteOfDefendingWallItem.getPosition().x;
                        float defendingWallItemY = _spriteOfDefendingWallItem.getPosition().y;
                        sf::FloatRect defendingWallItemBox(defendingWallItemX - widthdefendingWallItemBox / 2, defendingWallItemY - heightdefendingWallItemBox / 2, widthdefendingWallItemBox, heightdefendingWallItemBox);
                        if (defendingWallItemBox.contains(x, y))
                        {
                            if (_money >= _priceDefendingWallItem)
                            {
                                for (auto& player : _playerStorer)
                                {
                                    _defendingWallIsUnlocked = true;
                                    _money -= _priceDefendingWallItem;
                                    //_moneySpentEffectSound.play();
                                }
                            }

                        }
                        */
                    }
                    if (_startingPhase)
                    {
                        if (!_pause)
                        {
                            if (_spriteOfStartingDirectionUpAndRight.getGlobalBounds().contains(x, y))
                            {
                                //std::cout << "yesGO" << std::endl;
                                _ball.isGoingRight(true);
                                _ball.isGoingUp(true);

                            }

                            else if (_spriteOfStartingDirectionRight.getGlobalBounds().contains(x, y))
                            {
                                _ball.isGoingRight(true);
                                std::cout << "oh yeah" << std::endl;
                            }

                            else if (_spriteOfStartingDirectionDownAndRight.getGlobalBounds().contains(x, y))
                            {
                                _ball.isGoingRight(true);
                                _ball.isGoingDown(true);
                            }

                            _waveIsInProgress = true;
                        }

                        else
                        {
                            _pause = false;
                        }

                    }
                    float widthRestartButton = _textureOfRestartButton.getSize().x;
                    float heightRestartButton = _textureOfRestartButton.getSize().y;
                    sf::FloatRect restartButtonBox(_spriteOfRestartButton.getPosition().x - widthRestartButton / 2, _spriteOfRestartButton.getPosition().y - heightRestartButton / 2, widthRestartButton, heightRestartButton);
                    if (restartButtonBox.contains(x, y))
                    {
                        if (_gameOver)
                        {
                            restart();
                            _gameOver = false;
                        }

                        else if (_win)
                        {
                            restart();
                            _win = false;
                        }
                         

                    }

                    if (!_pause)
                    {
                        for (auto& player : _playerStorer)
                        {

                            player.getSprite().setRotation(player.getRotationOfBasicAttack());
                            player.isAttacking(true);
                        }
                    }

                    if (_pause)
                    {
                        _pause = false;
                    }

                    if (_playerHasLeveledUp && _upgradePhase)
                    {
                        for (auto& player : _playerStorer)
                        {
                           

                            if (_flipperIsUnlocked && !_okButtonFlipperHasBeenPressed)
                            {
                                if (_spriteOfFlipperUnlocked.getGlobalBounds().contains(x, y))
                                {
                                    _okButtonFlipperHasBeenPressed = true;
                                    _spriteOfFlipperUnlocked.setPosition(-100, -100);
                                    //std::cout << "nice" << std::endl;
                                }
                            }
                           

                            if (_dashIsUnlocked && !_okButtonDashHasBeenPressed)
                            {
                                if (_spriteOfDashUnlocked.getGlobalBounds().contains(x, y))
                                {
                                    _okButtonDashHasBeenPressed = true;
                                    _spriteOfDashUnlocked.setPosition(-100, -100);
                                    //std::cout << "nice" << std::endl;
                                }
                            }

                            if (_regenIsUnlocked && !_okButtonRegenHasBeenPressed)
                            {
                                if (_spriteOfRegenUnlocked.getGlobalBounds().contains(x, y))
                                {
                                    _okButtonRegenHasBeenPressed = true;
                                    _spriteOfRegenUnlocked.setPosition(-100, -100);
                                    //std::cout << "nice" << std::endl;
                                }
                            }

                            sf::FloatRect buttonIncreaseSpeedBox(_speedPointsText.getPosition().x, _speedPointsText.getPosition().y + 30, 50, 50);
                            if (buttonIncreaseSpeedBox.contains(event.mouseButton.x, event.mouseButton.y))
                            {
                                if (_nbOfAbiliyPoints > 0)
                                {
                                    _increaseAbilityEffectSound.play();
                                    _nbSpeedPoints++;
                                    _nbOfAbiliyPoints--;
                                    player.setSpeed(player.getBaseSpeed() + 0.15);
                                    if (player.getBaseSpeed() >= 12.f)
                                    {
                                        player.setBaseSpeed(12.f);
                                    }
                                    if (_nbSpeedPoints >=2)
                                    {
                                        _dashIsUnlocked = true;
                                    }
                                    if (_nbSpeedPoints >= 10)
                                    {
                                        _nbSpeedPoints = 10;
                                    }
                                    std::cout << "player enter the speed force!" << std::endl;
                                    std::cout << "new speed: " << player.getSpeed() << std::endl;
                                    std::cout << "nb speed points:" << _nbSpeedPoints << std::endl;
                                }

                                else
                                {
                                    //std::cout << "looser" << std::endl;
                                }

                            }

                            sf::FloatRect buttonIncreaseAttackBox(_attackPointsText.getPosition().x, _attackPointsText.getPosition().y + 10, 30, 30);
                            if (buttonIncreaseAttackBox.contains(event.mouseButton.x, event.mouseButton.y))
                            {
                                if (_nbOfAbiliyPoints > 0)
                                {
                                    _increaseAbilityEffectSound.play();
                                    _nbAttackPoints++;
                                    _nbOfAbiliyPoints--;
                                    if (_nbAttackPoints >= 5)
                                    {
                                        _flipperIsUnlocked = true;
                                    }
                                    if (_nbAttackPoints >= 10)
                                    {
                                        _nbAttackPoints = 10;
                                    }
                                    player.setBaseAtk(player.getBaseAtk() + (0.15 * player.getBaseAtk() * 0.23));
                                    std::cout << "player enter the attack force!" << std::endl;
                                    std::cout << "new atk:" << std::endl;
                                    std::cout << "nb attack points:" << _nbAttackPoints << std::endl;

                                }

                                else
                                {
                                    //std::cout << "looser" << std::endl;
                                }

                            }

                            sf::FloatRect buttonIncreaseMaxHpBox(_maxHpPointsText.getPosition().x, _maxHpPointsText.getPosition().y+5,30, 30);
                            if (buttonIncreaseMaxHpBox.contains(event.mouseButton.x, event.mouseButton.y))
                            {
                                if (_nbOfAbiliyPoints > 0)
                                {
                                    _increaseAbilityEffectSound.play();
                                    _nbMaxHpPoints++;
                                    _nbOfAbiliyPoints--;
                                    if (_nbMaxHpPoints >= 5)
                                    {
                                        _regenIsUnlocked = true;
                                    }
                                    if (_nbMaxHpPoints >= 10)
                                    {
                                        _nbMaxHpPoints = 10;
                                    }
                                        
                                    player.setBaseMaxHp(player.getBaseMaxHp() + (0.35 * player.getBaseMaxHp() + (0.1 * player.getBaseMaxHp())) * 0.77);
                                    std::cout << "player enter the hp force!" << std::endl;
                                    std::cout << "new max hp!" << player.getMaxHp() << std::endl;
                                    std::cout << "nb max hp points:" << _nbMaxHpPoints<< std::endl;
                                }

                                else
                                {
                                   // std::cout << "looser" << std::endl;
                                }

                            }


                        }
                    }
                   
                    
                }

                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    for (auto& player : _playerStorer)
                    {
                        if (_dashIsUnlocked)
                        {
                            player.isDashing(true);
                            _dashUnleashed = true;
                        }
                        
                        
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    for (auto& player : _playerStorer)
                    {
                        player.getSprite().setRotation(0.f);
                        if (_regenIsUnlocked)
                        {
                            if (_playerIsHealing)
                            {
                                _playerIsHealing = false;
                                _regenEffectSound.play();
                            }
                            
                        }
                      
                    }
                }
            }

		}

	void Game::update()
	{
        _world.Step(1 / 60.f, 8, 3);
	    _settings.getGameWindow().clear(sf::Color::White);
        float x = sf::Mouse::getPosition(_settings.getGameWindow()).x;
        float y = sf::Mouse::getPosition(_settings.getGameWindow()).y;
        //std::cout << "ball speed:" <<_ball.getCurrentSpeed() << std::endl;
        if (!_gameOver)
        {
            if (_mainTheme.getStatus() != 2)
            {
                _mainTheme.play();
            }
        }

        
        if (_startingPhase && !_waveIsInProgress)
        {

            float sizeOfBall = _ball.getCollider().getRadius() * 2;
            float widthStartingDirectionArrow = _textureOfStartingDirection.getSize().x;
            float heightStartingDirectionArrow = _textureOfStartingDirection.getSize().y;
            for (auto& player : _playerStorer)
            {
                _ball.getCollider().setPosition(player.getSprite().getPosition().x + 0.7 * sizeOfBall, player.getSprite().getPosition().y);
            }

            _spriteOfStartingDirectionRight.setPosition(_ball.getCollider().getPosition().x + widthStartingDirectionArrow / 2 + 1.2 * sizeOfBall, _ball.getCollider().getPosition().y);
            if (_spriteOfStartingDirectionRight.getGlobalBounds().contains(x, y))
            {
                _spriteOfStartingDirectionRight.setColor(sf::Color(214, 214, 214, 100));
            }
            else
            {
                _spriteOfStartingDirectionRight.setColor(sf::Color(255, 255, 255, 255));
            }
            if (_wave == 0)
            {
                float spriteOfStartingDirectionRightX = _spriteOfStartingDirectionRight.getPosition().x;
                float spriteOfStartingDirectionRightY = _spriteOfStartingDirectionRight.getPosition().y;
                _textAskingToPickDirection.setPosition(spriteOfStartingDirectionRightX + widthStartingDirectionArrow / 2, spriteOfStartingDirectionRightY - 45);
            }

            _spriteOfStartingDirectionUpAndRight.setPosition(_ball.getCollider().getPosition().x + widthStartingDirectionArrow / 2 + 0.1 * sizeOfBall, _ball.getCollider().getPosition().y - 2.2 * heightStartingDirectionArrow);
            _spriteOfStartingDirectionUpAndRight.setRotation(-45);
            if (_spriteOfStartingDirectionUpAndRight.getGlobalBounds().contains(x, y))
            {
                _spriteOfStartingDirectionUpAndRight.setColor(sf::Color(214, 214, 214, 100));
            }
            else
            {
                _spriteOfStartingDirectionUpAndRight.setColor(sf::Color(255, 255, 255, 255));
            }



            _spriteOfStartingDirectionDownAndRight.setPosition(_ball.getCollider().getPosition().x + widthStartingDirectionArrow / 2 + 0.1 * sizeOfBall, _ball.getCollider().getPosition().y + 2.2 * heightStartingDirectionArrow);
            _spriteOfStartingDirectionDownAndRight.setRotation(45);
            if (_spriteOfStartingDirectionDownAndRight.getGlobalBounds().contains(x, y))
            {
                _spriteOfStartingDirectionDownAndRight.setColor(sf::Color(214, 214, 214, 100));
            }
            else
            {
                _spriteOfStartingDirectionDownAndRight.setColor(sf::Color(255, 255, 255, 255));
            }



        }
      
        if (_wave != 0)
        {
            _waveText.setString("WAVE " + std::to_string(_wave));
        }

        if (_wave == 0)
        {
            _waveText.setString("WAVE " + std::to_string(_wave) + " (training)");
        }
        if (_wave == 0 && !_upgradePhase)
        {
           
            float widthBattleArea = _settings.getWidthOfBattleAreaBorders();
            float heighBattleArea = _settings.getHeightOfBattleAreaBorders();
            float battleAreaX = _settings.getBattleAreaBorders().getPosition().x;
            float battleAreaY = _settings.getBattleAreaBorders().getPosition().y;
            float widthLeftIndicatorDictacticiel = _textureOfDictacticielLeftMovement.getSize().x;
            float heightLeftIndicatorDictacticiel = _textureOfDictacticielLeftMovement.getSize().y;
            if (_spriteOfDictacticielLeftMovement.getPosition().x < battleAreaX + widthLeftIndicatorDictacticiel / 2 + 10)
            {
                //std::cout << "woww" << std::endl;
                _spriteOfDictacticielLeftMovement.setPosition(battleAreaX + widthLeftIndicatorDictacticiel / 2 + 100, battleAreaY + heightLeftIndicatorDictacticiel / 2 + 30);
            }
            _spriteOfDictacticielLeftMovement.move(-0.8, 0);


            float widthRightIndicatorDictacticiel = _textureOfDictacticielRightMovement.getSize().x;
            float heightRightIndicatorDictacticiel = _textureOfDictacticielRightMovement.getSize().y;
            if (_spriteOfDictacticielLeftMovement.getPosition().x < battleAreaX + widthLeftIndicatorDictacticiel / 2 + 10)
            {
                //std::cout << "woww" << std::endl;
                _spriteOfDictacticielRightMovement.setPosition(battleAreaX + widthRightIndicatorDictacticiel / 2 + 100, battleAreaY + heightRightIndicatorDictacticiel / 2 + 90);
            }
            _spriteOfDictacticielRightMovement.move(0.8, 0);


            float widthUpIndicatorDictacticiel = _textureOfDictacticielUpMovement.getSize().x;
            float heightUpIndicatorDictacticiel = _textureOfDictacticielUpMovement.getSize().y;
            if (_spriteOfDictacticielLeftMovement.getPosition().x < battleAreaX + widthLeftIndicatorDictacticiel / 2 + 10)
            {
                //std::cout << "woww" << std::endl;
                _spriteOfDictacticielUpMovement.setPosition(battleAreaX + widthUpIndicatorDictacticiel / 6 + widthUpIndicatorDictacticiel / 2, battleAreaY + heightUpIndicatorDictacticiel / 2 + 218);
            }
            _spriteOfDictacticielUpMovement.move(0, -0.8);


            float widthDownIndicatorDictacticiel = _textureOfDictacticielDownMovement.getSize().x;
            float heightDownIndicatorDictacticiel = _textureOfDictacticielDownMovement.getSize().y;
            if (_spriteOfDictacticielLeftMovement.getPosition().x < battleAreaX + widthLeftIndicatorDictacticiel / 2 + 10)
            {
               //std::cout << "woww" << std::endl;
                _spriteOfDictacticielDownMovement.setPosition(battleAreaX + widthDownIndicatorDictacticiel / 6 + widthDownIndicatorDictacticiel / 2, battleAreaY + heightDownIndicatorDictacticiel / 2 + 250);
            }
            _spriteOfDictacticielDownMovement.move(0, 0.8);


            float widthAttackIndicatorDictacticiel = _textureOfDictacticielAttackMovementRed2.getSize().x;
            float heightAttackIndicatorDictacticiel = _textureOfDictacticielAttackMovementRed2.getSize().y;
           // _spriteOfDictacticielAttackMovement.setPosition(battleAreaX + widthAttackIndicatorDictacticiel / 2 + 525, battleAreaY + heightAttackIndicatorDictacticiel / 2 + 5);
            for (auto& player : _playerStorer)
            {
                _spriteOfDictacticielAttackMovement.setPosition(player.getSprite().getPosition().x - widthAttackIndicatorDictacticiel, (player.getSprite().getPosition().y));
            }
            
            _spriteOfDictacticielAttackMovement.setTexture(_textureOfDictacticielAttackMovementWhite2);
            if (_timerDictacticiel > 50.f)
            {
                //std::cout << "yes?" << std::endl;
                _spriteOfDictacticielAttackMovement.setTexture(_textureOfDictacticielAttackMovementRed2);
                _timerDictacticiel = 0;
            }

          
        }
        else if (_wave == 0 && _upgradePhase)
        {
            for (auto& player : _playerStorer)
            {
                player.setHp(player.getMaxHp());
            }
            _spriteOfDictacticielLeftMovement.setPosition(-100, -100);
            _spriteOfDictacticielRightMovement.setPosition(-100, -100);
            _spriteOfDictacticielUpMovement.setPosition(-100, -100);
            _spriteOfDictacticielDownMovement.setPosition(-100, -100);
            _spriteOfDictacticielAttackMovement.setPosition(-100, -100);
        }
        

        float widthMoney = _textureOfMoney.getSize().x;
        float heighMoney = _textureOfMoney.getSize().y;
        _spriteOfMoney.setPosition(_settings.getBattleAreaBorders().getPosition().x + widthMoney / 3, _settings.getBattleAreaBorders().getPosition().y - heighMoney / 2 - _ceiling.getSize().y / 2);
        _moneyText.setPosition(_spriteOfMoney.getPosition().x + widthMoney / 2, _spriteOfMoney.getPosition().y - _moneyText.getCharacterSize() /1.7);
        _moneyText.setString(std::to_string((int)_money));
        float widthXp = _textureOfEmptyXpBar.getSize().x;
        float heightXp = _textureOfEmptyXpBar.getSize().y;
        _spriteOfEmptyXpBar.setPosition(_settings.getBattleAreaBorders().getPosition().x + _settings.getWidthOfBattleAreaBorders() / 3.1 - widthXp / 2, _settings.getBattleAreaBorders().getPosition().y - heightXp / 2 - _ceiling.getSize().y / 2);
        _spriteOfFullXp.setPosition(_spriteOfEmptyXpBar.getPosition().x, _spriteOfEmptyXpBar.getPosition().y);
      

        //std::cout << _nbEnemies << std::endl;
        if (_nbEnemies <= 0)
        {      
            if (_wave != 0)
            {
                _upgradePhase = true;
            }

            else
            {
                if (!_upgradePhase)
                {
                    _spawnPoints.erase(_spawnPoints.begin(), _spawnPoints.end());
                    _enemies.erase(_enemies.begin(), _enemies.end());
                    initEnemies();
                    initHealthBarsOfEnemies();
                    initReactionTimeBarsOfEnemies();
                }
               
            }
           

        }
       /* for (auto& player : _playerStorer)
        {
            if (_ball.hasCollidedWithPlayer()
                && !_ball.headingUp()
                && !_ball.headingDown()
                && !_ball.headingLeft()
                && !_ball.headingRight())
            {
                _ball.isGoingUp(true);
               // _ball.isGoingRight(true);
            }
        }*/

        

        ////////////////////////PLAYER  UDPATES/////////////////////////////
        updatePositionOfHealthBarPlayer(); //update position of player healthbar
        for (auto& player: _playerStorer)
        {
            player.update();
            if (_wave == 0)
            {
                _indicationForApproachingEnemies.setPosition(player.getSprite().getPosition().x - 50, player.getSprite().getPosition().y - 20);
            }
          
            if (player.getHealth().getHp() <= 0)
            {

                auto it = _playerStorer.begin();
                _playerStorer.erase(it);
                if (_wave != 0)
                {
                    _gameOver = true;
                }

                else
                {
                    initPlayer();
                    initHealthBarPlayer();
                  
                }
               
            }
        }
        for (auto& player : _playerStorer)
        {
            if (player.attacking())
            {
                _attackEffectSound.play();
                for (auto& enemy : _enemies)
                {
                    if (player.getHitBoxOfBasicAtk().intersects(enemy.getBodySprite().getGlobalBounds()))
                    {   
                        
                        if (_regenIsUnlocked)
                        {
                            player.setHp(player.getHp() + (0.05 * player.getMaxHp()));
                            _playerIsHealing = true;
                           // _regenEffectSound.play();                           
                        }
                      
                        
                        if (player.getHp() >= player.getMaxHp())
                        {
                            player.setHp(player.getMaxHp());
                        }
                        enemy.getDamage(player.getAtk() / 3);
                        if (!_upgradePhase)
                        {
                            _hitEnemyEffectSound.play();
                        }
                       
                        //std::cout << enemy.getHp() << std::endl;
                        //std::cout << "enemy hp remaining:" << enemy.getHealth().getHp() << std::endl;
                        //std::cout << "ouch" << std::endl;
                        if (enemy.getHp() <= 0)
                        {
                            if (enemy.getHp() <= 0 && enemy.getBodySprite().getPosition().x != -1000)
                            {
                                _ball.setCollisionWithEnemy(false);
                                enemy.getBodySprite().setPosition(-1000, -1000);
                                enemy.getLeftWingSprite().setPosition(-1000, -1000);
                                enemy.getRightWingSprite().setPosition(-1000, -1000);
                                enemy.getTailSprite().setPosition(-1000, -1000);
                                enemy.getHealthBarEmpty().setPosition(-1000, -1000);
                                enemy.getHealthbar().setPosition(-1000, -1000);
                                enemy.getHitboxView().setPosition(1000, -1000);
                                enemy.getHitbox().left = -1000;
                                enemy.getHitbox().top = -1000;
                                _nbEnemies--;
                                for (auto& player : _playerStorer)
                                {
                                    player.setXpGain(enemy.getXpDrop());
                                    _xpGainEffectSound.play();
                                    _money += enemy.getMoneyDrop();
                                }

                            }

                            //enemy.getHealth().setHp(enemy.getHealth().getMaxHp());

                        }


                        
                        //for (auto& healthbarOfEnemy : _healthBarsOfEnemies)
                        //{
                          //  healthbarOfEnemy.update();
                            //std::cout << "hey I'm an healthbar for this enemy!" << std::endl;
                            //std::cout << "he has " << healthbarOfEnemy.getDamageablePtr()->getHealth().getHp() << "hp" << std::endl;
                        //}
                    }

                   

                   
                }

                if (player.getHitBoxOfBasicAtk().intersects(_ball.getCollider().getGlobalBounds())
                    || player.getHitBoxOfBasicAtk().contains(_ball.getCollider().getGlobalBounds().left, _ball.getCollider().getGlobalBounds().top))
                {
                    //std::cout << "PLAYER IS HIT 1" << std::endl;
                   /* _ball.isGoingDown(true);
                    _ball.isGoingRight(true);
                    _ball.isGoingUp(false);
                    _ball.isGoingLeft(false);*/
                    _ball.isGoingRight(true);
                    _ball.isGoingLeft(false);
                    _intersectCounterForPlayer++;
                    if (_intersectCounterForPlayer == 1)
                    {
                        if (_ball.hasCollidedWithEnemy())
                        {
                            if (_ball.hasCollidedWithEnemy())
                            {
                                if (_reductionDamageIsUnlocked)
                                {
                                    //player.getDamage(_ball.getAtk() / 2);
                                    _hitEnemyEffectSound.play();
                                   
                                }

                                else
                                {
                                    //player.getDamage(_ball.getAtk() * 0.6);
                                    //std::cout << "reducing damages" << std::endl;
                                    _hitEnemyEffectSound.play();
                                }



                                if (!_ball.hasCollidedWithPlayerCamp())
                                {
                                    _defendingWallIsActive = true;
                                }

                                _ball.setCollisionWithEnemy(false);
                                _ball.setCollisionWithEnemyCamp(false);
                            }
                        }
                    }
                   

                    if (_ball.getCollider().getScale().x == 5 && _ball.getCollider().getScale().y == 5)
                    {
                        if (_wave % 10 == 0)
                        {
                            _ballSmallingEffectSound.play();
                            _ball.getCollider().setScale(sf::Vector2f(1, 1));
                        }
                        
                    }

                    if (_flipperIsUnlocked)
                    {
                        _flipperEffectSound.play();
                        _flipperUnleashed = true;
                      
                        //std::cout << "flipper " << std::endl;
                        _ball.setCurrentSpeed(_ball.getBaseSpeed() + 17.5);
                        _ball.getCollider().setFillColor(sf::Color(197, 10, 52));
                        
                        
                    }

                    if(!_flipperIsUnlocked)
                    {
                        _ball.setCurrentSpeed(_ball.getBaseSpeed() + (0.5 * player.getSpeed()));
                    }

                    if (_ball.getCurrentSpeed() >= 25.f)
                    {
                        _ball.setCurrentSpeed(25.f);
                    }

                    _ball.setCollisionWithPlayer(true);
                   
                }

                _ball.setCollisionWithPlayer(true);
                
                player.isAttacking(false);

            }

            if (_playerIsHealing)
            {
            
                _spriteOfPlayerHealingState.setPosition(player.getSprite().getPosition().x, player.getSprite().getPosition().y);
                _spriteOfPlayerHealingState.setRotation(player.getSprite().getRotation());
                //_playerIsHealing = false;
            }

            else
            {
                _spriteOfPlayerHealingState.setPosition(-100, -100);
            }
        }

        
        for (auto& player : _playerStorer)
        {
            if (player.dashing())
            {
                _dashEffectSound.play();
                if (player.getHitboxOfDash().contains(_ball.getCollider().getPosition().x, _ball.getCollider().getPosition().y))
                {
                    float widthPlayer = player.getTexture().getSize().x * player.getSprite().getScale().x;
                    float heightPlayer = player.getTexture().getSize().y * player.getSprite().getScale().y;
                    float radiusBall = _ball.getCollider().getRadius();
                    _ball.getCollider().setPosition(player.getSprite().getPosition().x + widthPlayer / 2 + radiusBall, _ball.getCollider().getPosition().y);
                    if (!player.headingRight() && !player.headingDown() && !player.headingUp() && !player.headingLeft())
                    {
                        _ball.isGoingRight(true);
                        _ball.isGoingLeft(false);
                        _ball.setCurrentSpeed(_ball.getBaseSpeed() + 17.5);
                    }

                    if (player.headingRight())
                    {
                        _ball.isGoingRight(true);
                        _ball.isGoingLeft(false);
                        _ball.setCurrentSpeed(_ball.getBaseSpeed() + 17.5);
                    }

                    if (player.headingLeft())
                    {
                        _ball.isGoingRight(false);
                        _ball.isGoingLeft(true);
                        _ball.setCurrentSpeed(_ball.getBaseSpeed());
                    }

                 
                    
                    
               
                   
                   
                }

                if (player.headingRight())
                {
                    if (player.getSprite().getPosition().x <= player.getHitboxOfDash().left + player.getHitboxOfDash().width)
                    {
                        // std::cout << "yes" << std::endl;
                        player.move(45, 0);
                    }

                    else
                    {
                        player.isDashing(false);
                    }
                }

                else if(player.headingLeft())
                {
                    if (player.getSprite().getPosition().x >= player.getHitboxOfDash().left)
                    {
                        // std::cout << "yes" << std::endl;
                        player.move(-45, 0);
                    }

                    else
                    {
                        player.isDashing(false);
                    }
                }

                else if (!player.headingRight() && !player.headingDown() && !player.headingUp() && !player.headingLeft())
                {
                    if (player.getSprite().getPosition().x <= player.getHitboxOfDash().left + player.getHitboxOfDash().width)
                    {
                        // std::cout << "yes" << std::endl;
                        player.move(45, 0);
                    }

                    else
                    {
                        player.isDashing(false);
                    }

                }

                else if (player.headingDown() || player.headingUp())
                {
                    if (player.getSprite().getPosition().x <= player.getHitboxOfDash().left + player.getHitboxOfDash().width)
                    {
                        // std::cout << "yes" << std::endl;
                        player.move(60, 0);
                    }

                    else
                    {
                        player.isDashing(false);
                    }

                }

                for (auto& enemy : _enemies)
                {
                    if (enemy.getBodySprite().getGlobalBounds().intersects(player.getRange().getGlobalBounds()))
                    {
                        enemy.getDamage(player.getSpeed());
                        if (!_upgradePhase)
                        {
                            _hitEnemyEffectSound.play();
                        }
                        if (enemy.getHp() <= 0)
                        {
                            _ball.setCollisionWithEnemy(false);
                            auto it = _enemies.begin();
                            int j = 0;
                            while (_enemies[j].getHp() != enemy.getHp())
                            {
                                j++;
                                it++;
                            }

                            if (_wave != 0)
                            {

                                player.setXpGain(enemy.getXpDrop());
                                _xpGainEffectSound.play();
                            }
                           
                            _money += enemy.getMoneyDrop();
                            _enemies.erase(it);
                            _nbEnemies--;

                            enemy.getBodyTexture().loadFromFile("data/Enemy/body.png");
                            enemy.getBodySprite().setTexture(enemy.getBodyTexture());

                            enemy.getLeftWingTexture().loadFromFile("data/Enemy/leftWing.png");
                            enemy.getLeftWingSprite().setTexture(enemy.getLeftWingTexture());

                            enemy.getRightWingTexture().loadFromFile("data/Enemy/rightWing.png");
                            enemy.getRightWingSprite().setTexture(enemy.getRightWingTexture());


                            enemy.getTailTexture().loadFromFile("data/Enemy/tail.png");
                            enemy.getTailSprite().setTexture(enemy.getTailTexture());
                        }
                    }
                }

               
             

                

               

               
            }

            //player.isDashing(false);

           
        }

        if (_gameOver)
        {
            gameOver();
        }
        else
        {
            _gameOverText.setPosition(-100, -100); //game over text
            _spriteOfGameOver.setPosition(-100, -100); //game over sprite
            _spriteOfRestartButton.setPosition(-100, -100);  //restart button
        }
        if (_win)
        {
         
            win();
        }

        else
        {
            _winText.setPosition(-100, -100); //win text
            _spriteOfWin.setPosition(-100, -100); //win sprite
            ///_spriteOfRestartButton.setPosition(-100, -100);  //restart button
        }
        ////////////////////////PLAYER UPDATES/////////////////////////////
        
	   /* for (auto& enemy : _enemies)
	    {
			for (auto& healthObserver : enemy.getHealth().getObserversList())
			{
                std::cout << healthObserver->getHealthPtr()->getValue() << "hp remaining" << std::endl;
			}
	    }
	    */

        
        float ballXpos = _ball.getSprite().getPosition().x;
        float ballYpos = _ball.getSprite().getPosition().y;
        float widthball = _ball.getTexture().getSize().x * _ball.getSprite().getScale().x;
        float heightball = _ball.getTexture().getSize().y * _ball.getSprite().getScale().y;
        sf::FloatRect ballCollider(ballXpos - (widthball / 2) + _outlineThickness, ballYpos - (heightball / 2.f) - 10, widthball - _outlineThickness + 15, heightball + 15);
        float widthBallCollider = ballCollider.width;
        float heightBallCollider = ballCollider.height;
        _ball.update();
        _ballView.setSize(sf::Vector2f(widthBallCollider, heightBallCollider));
        _ballView.setFillColor(sf::Color::Black);
        _ballView.setPosition(ballCollider.left, ballCollider.top);

       
        for (auto& enemy : _enemies)
        {
            //std::cout << enemy.getHp() << std::endl;
            if (_ball.getCollider().getGlobalBounds().intersects(enemy.getHitbox()) && _waveIsInProgress)
            {
               
                float ballScaleX = _ball.getCollider().getScale().x;
                float ballScaleY = _ball.getCollider().getScale().y;
                _intersectCounterForEnemies++;
                if (_intersectCounterForEnemies == 1)
                {
                    std::cout << "ball touched enemy" << std::endl;
                    _ball.setCollisionWithEnemy(true);
                    if (_wave == 0)
                    {
                        _explanationBallHitEnemy = true;
                        if (_explanationBallHitEnemy && !_explanationBallHitEnemySeen)
                        {
                            _textOfExplanationBallHitEnemy.setPosition(enemy.getBodySprite().getPosition().x - 555, enemy.getBodySprite().getPosition().y + 65);
                            _theGreenZoneText.setPosition(-1000, -1000);
                            _playerCampDescription.setPosition(-1000, -1000);
                            _pause = true;
                        }
                    }
                   
                    //_ball.getCollider().setFillColor(enemy.getColor());
                    //_ball.getCollider().setOutlineColor(enemy.getColor());
                    if (enemy.getType() == "boss")
                    {
                        if (_ball.getCollider().getScale().x < 5 && _ball.getCollider().getScale().y < 5)
                        {
                            _ballGrowingEffectSound.play();
                            _ball.getCollider().scale(5, 5);
                        }

                        
                    }

                    
                  
                    
                    if (_startingPhase)
                    {
                        if (!_flipperUnleashed)
                        {
                            int randDir;
                            do
                            {
                                randDir = 1 + rand() % 2;
                            } while (randDir <= 0);

                            if (randDir == 1)
                            {
                                std::cout << "1" << std::endl;
                                _ball.isGoingDown(true);
                                _ball.isGoingRight(false);
                                _ball.isGoingUp(false);
                                _ball.isGoingLeft(true);

                            }

                            else if (randDir == 2)
                            {
                                std::cout << "2" << std::endl;
                                _ball.isGoingDown(false);
                                _ball.isGoingRight(false);
                                _ball.isGoingUp(true);
                                _ball.isGoingLeft(true);
                            }

                            _startingPhase = false;
                            _waveIsInProgress = true;
                            _defendingWallIsActive = true;

                        }

                    }

                    if (_ball.hasCollidedWithPlayer())
                    {
                        for (auto& player : _playerStorer)
                        {
                            if (_dashUnleashed)
                            {
                                _dashUnleashed = false;
                                _ball.setCurrentSpeed(_ball.getBaseSpeed());
                            }

                            if (_flipperUnleashed)
                            {
                                if (_wave % 10 != 0)
                                {
                                    if (_ball.getCollider().getScale().x == 5 && _ball.getCollider().getScale().y == 5)
                                    {
                                        enemy.getDamage(enemy.getMaxHp());
                                    }
                                }


                                enemy.getDamage(player.getAtk() + (0.50 * player.getAtk()) * _ball.getCollider().getScale().x);
                                if (!_upgradePhase)
                                {
                                    _hitEnemyEffectSound.play();
                                }
                            }

                            if (!_flipperUnleashed)
                            {
                                if (_wave == 0)
                                {
                                    enemy.getDamage(enemy.getMaxHp() * 0.20);
                                    if (!_upgradePhase)
                                    {
                                        _hitEnemyEffectSound.play();
                                    }
                                }

                                else
                                {
                                    if (_wave % 10 != 0)
                                    {
                                        if (_ball.getCollider().getScale().x == 5 && _ball.getCollider().getScale().y == 5)
                                        {
                                            if (_waveIsInProgress)
                                            {
                                                _ballSmallingEffectSound.play();
                                                _ball.getCollider().setScale(sf::Vector2f(1, 1));
                                            }
                                            enemy.getDamage(enemy.getMaxHp());
                                        }

                                        else
                                        {
                                            enemy.getDamage(player.getAtk());
                                        }
                                    }
                                   

                                    
                                   
                                    if (!_upgradePhase)
                                    {
                                        _hitEnemyEffectSound.play();
                                    }
                                }
                                
                            }
                            
                            if (_regenIsUnlocked)
                            {
                                player.setHp(player.getHp() + player.getAtk());
                            }
                           
                            if (player.getHp() >= player.getMaxHp())
                            {
                                player.setHp(player.getMaxHp());
                            }
                        }
                       
                        if (!_flipperUnleashed)
                        {
                            _ball.setCurrentSpeed(_ball.getBaseSpeed() + ((enemy.getSpeed() * 0.5)));
                        }
                       
                        if (_ball.getCurrentSpeed() >= 25.f)
                        {
                            _ball.setCurrentSpeed(25.f);
                        }
                        _ball.setCollisionWithPlayer(false);
                    }

                    if (!_startingPhase)
                    {
                        if (!_flipperUnleashed)
                        {
                            if (_ball.headingLeft())
                            {
                                _ball.isGoingRight(true);
                                _ball.isGoingLeft(false);
                            }

                            if (_ball.headingRight())
                            {
                                _ball.isGoingRight(false);
                                _ball.isGoingLeft(true);
                            }
                        }

                    }
                 
                    _ball.setAtk(enemy.getAtk());

                  
                    if (enemy.getHp() <= 0 && enemy.getBodySprite().getPosition().x != -1000)
                    {
                        _ball.setCollisionWithEnemy(false);
                        enemy.getBodySprite().setPosition(-1000, -1000);
                        enemy.getLeftWingSprite().setPosition(-1000, -1000);
                        enemy.getRightWingSprite().setPosition(-1000, -1000);
                        enemy.getTailSprite().setPosition(-1000, -1000);
                        enemy.getHealthBarEmpty().setPosition(-1000, -1000);
                        enemy.getHealthbar().setPosition(-1000, -1000);
                        enemy.getHitboxView().setPosition(1000, -1000);
                        enemy.getHitbox().left = -1000;
                        enemy.getHitbox().top = -1000;
                        _nbEnemies--;
                        for (auto& player: _playerStorer)
                        {
                            if (_wave != 0)
                            {
                                player.setXpGain(enemy.getXpDrop());
                                _xpGainEffectSound.play();
                            }
                           
                            _money += enemy.getMoneyDrop();
                        }
                        
                    }

                  
                }

                
            }
            if (!checkAnyCollisionBetweenBallAndEnemies())
            {
                _intersectCounterForEnemies = 0;
            }
            if (!checkPlayerEntersAnyEnemyRange())
            {
                //std::cout << "no player" << std::endl;
                for (auto& enemy : _enemies)
                {
                    enemy.isReacting(false);
                    
                }
            }
           

            enemy.update();
            if (enemy.getHp() > 0)
            {
               
                if (enemy.getSpriteScaleX() > 1 && enemy.getSpriteScaleY() > 1
                    && enemy.getSpriteScaleX() < 1.7 && enemy.getSpriteScaleY() < 1.7)  // update position config of medium enemy health bar  (medium)
                {
                    //std::cout << "IM MEDIUM SIZED" << std::endl;
                    float heightHealthBar = enemy.getHealthBarEmpty().getSize().y;
                    float heightEnemyBody = enemy.getBodyTexture().getSize().y * enemy.getSpriteScaleY();
                    float healthBarXposition = enemy.getBodySprite().getPosition().x - 7.f * enemy.getSpriteScaleX();
                    float healthBarYposition = enemy.getBodySprite().getPosition().y - heightEnemyBody / 2.f - heightHealthBar / 2.f - enemy.getYOffset() - 13.f * enemy.getSpriteScaleY();
                    enemy.getHealthBarEmpty().setPosition(healthBarXposition, healthBarYposition);
                    enemy.getHealthbar().setPosition(healthBarXposition, healthBarYposition);
                    enemy.getHealthbar().setFillColor(enemy.getColor());

                    enemy.getReactionTimeBarEmpty().setPosition(healthBarXposition, healthBarYposition - 16);
                    enemy.getReactionTimeBar().setPosition(healthBarXposition, healthBarYposition - 16);

                }

                else if (enemy.getSpriteScaleX() >= 1.7 &&enemy.getSpriteScaleY() >= 1.7
                    && enemy.getSpriteScaleX() < 1.9 && enemy.getSpriteScaleY() < 1.9)  // update position config for big sized enemies health bar (big)
                {
                   // std::cout << "IM BIG SIZED" << std::endl;
                    float heightHealthBar = enemy.getHealthBarEmpty().getSize().y;
                    float heightEnemyBody = enemy.getBodyTexture().getSize().y * enemy.getSpriteScaleY();
                    float healthBarXposition = enemy.getBodySprite().getPosition().x - 24.f * enemy.getSpriteScaleX();
                    float healthBarYposition = enemy.getBodySprite().getPosition().y - heightEnemyBody / 2.f - heightHealthBar / 2.f - enemy.getYOffset() - 33.f * enemy.getSpriteScaleY();
                    enemy.getHealthBarEmpty().setPosition(healthBarXposition, healthBarYposition);
                    enemy.getHealthbar().setPosition(healthBarXposition, healthBarYposition);
                    enemy.getHealthbar().setFillColor(enemy.getColor());

                    enemy.getReactionTimeBarEmpty().setPosition(healthBarXposition, healthBarYposition - 16);
                    enemy.getReactionTimeBar().setPosition(healthBarXposition, healthBarYposition - 16);
                }

                else if (enemy.getSpriteScaleX() >= 1.9 && enemy.getSpriteScaleY() >= 1.9) // update position config for boss health bar and reactionTime bar (boss)
                {
                    float heightHealthBar = enemy.getHealthBarEmpty().getSize().y;
                    float heightEnemyBody = enemy.getBodyTexture().getSize().y * enemy.getSpriteScaleY();
                    float healthBarXposition = enemy.getBodySprite().getPosition().x - 72.f * enemy.getSpriteScaleX();
                    float healthBarYposition = enemy.getBodySprite().getPosition().y - heightEnemyBody / 2.f - heightHealthBar / 2.f - enemy.getYOffset() - 91.f * enemy.getSpriteScaleY();
                    enemy.getHealthBarEmpty().setPosition(healthBarXposition, healthBarYposition);
                    enemy.getHealthbar().setPosition(healthBarXposition, healthBarYposition);
                    enemy.getHealthbar().setFillColor(enemy.getColor());

                    enemy.getReactionTimeBarEmpty().setPosition(healthBarXposition, healthBarYposition - 26);
                    enemy.getReactionTimeBar().setPosition(healthBarXposition, healthBarYposition - 26 );
                }

                for (auto& player : _playerStorer)
                {
                    if (enemy.getRange().getGlobalBounds().intersects(player.getSprite().getGlobalBounds()))
                    {
                        //std::cout << "player detected" << std::endl;
                        //_iEnemyRange++;
                        if (_wave == 0 && !enemy.tracking())
                        {
                            _explanationReactionSpeedEnemy = true;
                            if (_explanationReactionSpeedEnemy && !_explanationReactionSpeedEnemySeen)
                            {
                                float widthSpriteOfExplanationReactionSpeedEnemy = _textureOfExplanationReactionSpeedEnemy.getSize().x;
                                float heightSpriteOfExplanationReactionSpeedEnemy = _textureOfExplanationReactionSpeedEnemy.getSize().y;
                                _spriteOfExplanationReactionSpeedEnemy.setPosition(enemy.getBodySprite().getPosition().x - widthSpriteOfExplanationReactionSpeedEnemy , enemy.getBodySprite().getPosition().y + heightSpriteOfExplanationReactionSpeedEnemy);
                                _pause = true;
                            }
                        }
                        enemy.isReacting(true);
                        if (enemy.getiReactionTime() > enemy.getReactionTime())
                        {
                            //TODO
                            enemy.setIReactionTime(0);
                            if (_wave != 0)
                            {
                                player.getDamage(enemy.getAtk() * 0.6);
                                _hitEnemyEffectSound.play();
                            }
                            else
                            {
                                player.getDamage(player.getMaxHp() * 0.15);
                                _hitEnemyEffectSound.play();
                            }
                            std::cout << "ouch" << std::endl;
                        }
                    }
                }

                if (enemy.tracking())
                {
                    enemy.isPlaying(false);
                    for (auto& player : _playerStorer)
                    {
                        if (enemy.getSpriteScaleX() > 1.9 && enemy.getSpriteScaleY() > 1.9)
                        {
                            if (enemy.getBodySprite().getPosition().x > player.getSprite().getPosition().x + 210)
                            {
                                enemy.getBodySprite().move(-enemy.getSpeed(), 0);
                            }

                            if (enemy.getBodySprite().getPosition().x < player.getSprite().getPosition().x + 210)
                            {
                                enemy.getBodySprite().move(enemy.getSpeed(), 0);
                            }

                            if (enemy.getBodySprite().getPosition().y > player.getSprite().getPosition().y + 210)
                            {
                                enemy.getBodySprite().move(0, -enemy.getSpeed());
                            }

                            if (enemy.getBodySprite().getPosition().y < player.getSprite().getPosition().y + 210)
                            {
                                enemy.getBodySprite().move(0, enemy.getSpeed());
                            }
                        }

                        else
                        {
                            if (enemy.getBodySprite().getPosition().x > player.getSprite().getPosition().x)
                            {
                                enemy.getBodySprite().move(-2.5, 0);
                            }

                            if (enemy.getBodySprite().getPosition().x < player.getSprite().getPosition().x)
                            {
                                enemy.getBodySprite().move(2.5, 0);
                            }

                            if (enemy.getBodySprite().getPosition().y > player.getSprite().getPosition().y)
                            {
                                enemy.getBodySprite().move(0, -2.5);
                            }

                            if (enemy.getBodySprite().getPosition().y < player.getSprite().getPosition().y)
                            {
                                enemy.getBodySprite().move(0, 2.5);
                            }
                        }
                       

                    }

                    if (_wave == 0)
                    {

                        _explanationEnemiesTargetingPlayer = true;
                        if (_explanationEnemiesTargetingPlayer && !_explanationEnemiesTargetingPlayerSeen)
                        {
                            _textOfExplanationEnemiesTargetingPlayer.setPosition(enemy.getBodySprite().getPosition().x - 555, enemy.getBodySprite().getPosition().y + 65);
                            float  textOfExplanationEnemiesTargetingPlayerX = _textOfExplanationEnemiesTargetingPlayer.getPosition().x;
                            float  textOfExplanationEnemiesTargetingPlayerY = _textOfExplanationEnemiesTargetingPlayer.getPosition().y;
                            _theGreenZoneText.setPosition(-1000, -1000);
                            _playerCampDescription.setPosition(-1000, -1000);
                            _pause = true;
                        }
                    }

                }
                   
                else if (enemy.playing())
                {
                    if (_ball.getCollider().getPosition().y + 220> enemy.getBodySprite().getPosition().y)
                    {
                        enemy.getBodySprite().move(0, enemy.getSpeed());

                    }

                    if (_ball.getCollider().getPosition().y < enemy.getBodySprite().getPosition().y - 220)
                    {
                        enemy.getBodySprite().move(0, -enemy.getSpeed());

                    }
                }
            }

         
            
        }

        for (auto& bloc : _blocsInBattle)
        {
            if (_ball.getCollider().getGlobalBounds().intersects(bloc.getCollider().getGlobalBounds()))
            {
                //i++;
                /*if (i == 1)
                {
                    std::cout << "ball touched a bloc" << std::endl;
                    if (_ball.headingLeft())
                    {
                        _ball.isGoingRight(true);
                        _ball.isGoingLeft(false);
                    }

                    else if (_ball.headingRight())
                    {
                        _ball.isGoingRight(false);
                        _ball.isGoingLeft(true);
                    }*/
                    //i = 0;

               // }

            }

        }
        
       

      
        if (_ball.getCollider().getGlobalBounds().intersects(_ground.getGlobalBounds()))
        {
            //_bouncingEffectSound.play();
            std::cout << "get up!" << std::endl;
           /* if (_flipperUnleashed)
            {
                _flipperUnleashed = false;
                _ball.setCurrentSpeed(_ball.getBaseSpeed());
            }*/
            _ball.isGoingUp(true);
            _ball.isGoingDown(false);

            
        }
        if (_ball.getCollider().getGlobalBounds().intersects(_ceiling.getGlobalBounds()))
        {
            //_bouncingEffectSound.play();
            std::cout << "get down!" << std::endl;
            /*if (_flipperUnleashed)
            {
                _flipperUnleashed = false;
                _ball.setCurrentSpeed(_ball.getBaseSpeed());
            }*/
            _ball.isGoingUp(false);
            _ball.isGoingDown(true);
        }
        if (_ball.getCollider().getGlobalBounds().intersects(_leftWall.getGlobalBounds()))
        {
            //_bouncingEffectSound.play();
            if (_flipperUnleashed)
            {
                _flipperUnleashed = false;
                _ball.setCurrentSpeed(_ball.getBaseSpeed());
                _ball.getCollider().setFillColor(sf::Color::White);
            }

            if (_dashUnleashed)
            {
                _dashUnleashed = false;
                _ball.setCurrentSpeed(_ball.getBaseSpeed());
            }
          
           
            if (!_upgradePhase)
            {
                for (auto& player : _playerStorer)
                {
                    if (_ball.hasCollidedWithEnemy() && !_ball.hasCollidedWithPlayer())
                    {
                        std::cout << "camp attacked by single enemy player didnt intercept" << std::endl;
                        if (_wave == 0)
                        {
                            _explanationBallHitPlayerCamp2 = true;
                            if (_explanationBallHitPlayerCamp2 && !_explanationBallHitPlayerCampSeen2)
                            {
                                float widthBattleArea = _settings.getWidthOfBattleAreaBorders();
                                float heighBattleArea = _settings.getHeightOfBattleAreaBorders();
                                float battleAreaX = _settings.getBattleAreaBorders().getPosition().x;
                                float battleAreaY = _settings.getBattleAreaBorders().getPosition().y;
                                
                                _textOfExplanationBallHitPlayerCamp2.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.3);
                                float  textOfExplanationBallHitPlayerCampX = _textOfExplanationBallHitPlayerCamp2.getPosition().x;
                                float  textOfExplanationBallHitPlayerCampY = _textOfExplanationBallHitPlayerCamp2.getPosition().y;
                                _theGreenZoneText.setPosition(-1000, -1000);
                                _playerCampDescription.setPosition(-1000, -1000);
                                _pause = true;
                            }
                        }
                        
                        if (_reductionDamageIsUnlocked)
                        {
                            player.getDamage(_ball.getAtk() / 2);
                            _hitEnemyEffectSound.play();
                        }

                        else
                        {

                            if (_wave != 0)
                            {
                                player.getDamage(_ball.getAtk());
                                _hitEnemyEffectSound.play();
                            }
                            
                            else
                            {
                                player.getDamage(player.getMaxHp() * 0.15);
                                _hitEnemyEffectSound.play();
                            }
                        }
                        
                        _ball.setCollisionWithEnemy(false);
                    }

                    else if(_ball.hasCollidedWithEnemyCamp())
                    {
                        if (_wave == 0)
                        {
                            _explanationBallHitPlayerCamp = true;
                            if (_explanationBallHitPlayerCamp && !_explanationBallHitPlayerCampSeen)
                            {
                                float widthBattleArea = _settings.getWidthOfBattleAreaBorders();
                                float heighBattleArea = _settings.getHeightOfBattleAreaBorders();
                                float battleAreaX = _settings.getBattleAreaBorders().getPosition().x;
                                float battleAreaY = _settings.getBattleAreaBorders().getPosition().y;
                                _textOfExplanationBallHitPlayerCamp.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.3);

                                float  textOfExplanationBallHitPlayerCampX = _textOfExplanationBallHitPlayerCamp.getPosition().x;
                                float  textOfExplanationBallHitPlayerCampY = _textOfExplanationBallHitPlayerCamp.getPosition().y;
                                _theGreenZoneText.setPosition(-1000, -1000);
                                _playerCampDescription.setPosition(-1000, -1000);
                                _pause = true;
                            }
                        }
                        std::cout << "player camp attacked by enemy camp, and player didnt intercept" << std::endl;
                        //std::cout << "player gets " << Enemy::getGroupAtk() << "group damage! wow" << std::endl;
                        //player.getDamage(Enemy::getGroupAtk());
                        //Enemy::setGroupAtk(0);
                        player.getDamage(player.getMaxHp() * 0.30);
                        _hitEnemyEffectSound.play();
                        _ball.setCollisionWithEnemyCamp(false);
                    }

                }
            }
           
           // std::cout << "get right!" << std::endl;
            _ball.isGoingRight(true);
            _ball.isGoingLeft(false);
            _ball.setAtk(0);
        }
        if (_ball.getCollider().getGlobalBounds().intersects(_rightWall.getGlobalBounds()))
        {
            //_bouncingEffectSound.play();
            if (_dashUnleashed)
            {
                _dashUnleashed = false;
                _ball.setCurrentSpeed(_ball.getBaseSpeed());
            }
            if (_startingPhase)
            {
                if (_flipperUnleashed)
                {
                    _flipperUnleashed = false;
                    _ball.getCollider().setFillColor(sf::Color::White);
                }
                int randDir;
                do
                {
                    randDir = 1 + rand() % 2;
                } while (randDir <= 0);

                if (randDir == 1)
                {
                    std::cout << "1" << std::endl;
                    _ball.isGoingDown(true);
                    _ball.isGoingRight(false);
                    _ball.isGoingUp(false);
                    _ball.isGoingLeft(true);

                }

                else if (randDir == 2)
                {
                    std::cout << "2" << std::endl;
                    _ball.isGoingDown(false);
                    _ball.isGoingRight(false);
                    _ball.isGoingUp(true);
                    _ball.isGoingLeft(true);
                }


                _startingPhase = false;
                _waveIsInProgress = true;
                _flipperUnleashed = false;
                _ball.getCollider().setFillColor(sf::Color::White);
                

                
                
            }
            //Enemy::setGroupAtk(0);
            _ball.setCurrentSpeed(_ball.getBaseSpeed());
            //std::cout << "get left!" << std::endl;
            if (_ball.hasCollidedWithPlayer())
            {
                
                for (auto& enemy : _enemies)
                {
                    for (auto& player : _playerStorer)
                    {
                        _ball.setAtk(player.getMaxHp() / 3);
                        if (enemy.getType() == "boss")
                        {
                            enemy.getDamage(enemy.getMaxHp() / 3);
                            if (!_upgradePhase)
                            {
                                _hitEnemyEffectSound.play();
                            }
                        }
                        else
                        {
                            if (_wave == 0)
                            {
                                enemy.getDamage(enemy.getMaxHp() * 0.20);
                                if (!_upgradePhase)
                                {
                                    _hitEnemyEffectSound.play();
                                }
                            }

                            else
                            {
                                enemy.getDamage(player.getAtk());
                                if (!_upgradePhase)
                                {
                                    _hitEnemyEffectSound.play();
                                }
                            }
                        }
                        
                    }
                 
                   if (enemy.getHp() <= 0 && enemy.getBodySprite().getPosition().x != -1000)
                   {
                       _ball.setCollisionWithEnemy(false);
                       enemy.getBodySprite().setPosition(-1000, -1000);
                       enemy.getLeftWingSprite().setPosition(-1000, -1000);
                       enemy.getRightWingSprite().setPosition(-1000, -1000);
                       enemy.getTailSprite().setPosition(-1000, -1000);
                       enemy.getHealthBarEmpty().setPosition(-1000, -1000);
                       enemy.getHealthbar().setPosition(-1000, -1000);
                       enemy.getHitboxView().setPosition(1000, -1000);
                       enemy.getHitbox().left = -1000;
                       enemy.getHitbox().top = -1000;
                       _nbEnemies--;
                       for (auto& player : _playerStorer)
                       {
                           _xpGainEffectSound.play();
                           player.setXpGain(enemy.getXpDrop());
                           _money += enemy.getMoneyDrop();
                       }
                       
                      
                   }
                }

                if (_wave == 0)
                {
                    _explanationBallHitEnemyCamp = true;
                    if (_explanationBallHitEnemyCamp && !_explanationBallHitEnemyCampSeen)
                    {
                        float widthBattleArea = _settings.getWidthOfBattleAreaBorders();
                        float heighBattleArea = _settings.getHeightOfBattleAreaBorders();
                        float battleAreaX = _settings.getBattleAreaBorders().getPosition().x;
                        float battleAreaY = _settings.getBattleAreaBorders().getPosition().y;
                        _textOfExplanationBallHitEnemyCamp.setPosition(_rightWall.getPosition().x - 400, battleAreaY + heighBattleArea / 1.3);
                        float  textOfExplanationBallHitEnemyCampX = _textOfExplanationBallHitEnemyCamp.getPosition().x;
                        float  textOfExplanationBallHitEnemyCampY = _textOfExplanationBallHitEnemyCamp.getPosition().y;
                        _theRedZoneText.setPosition(textOfExplanationBallHitEnemyCampX - 165, textOfExplanationBallHitEnemyCampY);
                        _pause = true;
                    }
                }
            }

            for (auto& enemy : _enemies)
            {
                if (enemy.getBodySprite().getPosition().x != -1000)
                {
                    //_ball.setAtk(_)
                    //float atk = enemy.getAtk();
                    //Enemy::setGroupAtk(Enemy::getGroupAtk() + atk);
                    //std::cout << "group atk :" << Enemy::getGroupAtk() << std::endl;
                }
               
            }

            if (!_startingPhase)
            {
                _ball.isGoingRight(false);
                _ball.isGoingLeft(true);
                if (_flipperUnleashed)
                {
                    _ball.getCollider().setFillColor(sf::Color::White);
                    _flipperUnleashed = false;
                    _ball.setCurrentSpeed(_ball.getBaseSpeed());
                }
                
            }
            _ball.setCollisionWithEnemyCamp(true);
        }
        if (_ball.getCollider().getGlobalBounds().intersects(_defendingWall.getGlobalBounds()))
        {
            if (_wave == 0)
            {
                if (_defendingWallIsActive)
                {
                    _explanationBallHitDefendingWall = true;
                    if (_explanationBallHitDefendingWall && !_explanationBallHitDefendingWallSeen)
                    {
                        float widthBattleArea = _settings.getWidthOfBattleAreaBorders();
                        float heighBattleArea = _settings.getHeightOfBattleAreaBorders();
                        float battleAreaX = _settings.getBattleAreaBorders().getPosition().x;
                        float battleAreaY = _settings.getBattleAreaBorders().getPosition().y;                      
                        _textOfExplanationBallHitDefendingWall.setPosition(battleAreaX + 20, battleAreaY + heighBattleArea / 1.3);
                        float  textOfExplanationBallHitDefendingWallX = _textOfExplanationBallHitDefendingWall.getPosition().x;
                        float  textOfExplanationBallHitDefendingWallY = _textOfExplanationBallHitDefendingWall.getPosition().y;
                        _theDefendingWallText.setPosition(textOfExplanationBallHitDefendingWallX, textOfExplanationBallHitDefendingWallY - 20);
                        _theGreenZoneText.setPosition(-1000, -1000);
                        _playerCampDescription.setPosition(-1000, -1000);
                        _pause = true;
                    }
                }
               
            }

            if (_flipperUnleashed)
            {
                _flipperUnleashed = false;
                _ball.setCurrentSpeed(_ball.getBaseSpeed());
                _ball.getCollider().setFillColor(sf::Color::White);

            }

            if (_dashUnleashed)
            {
                _dashUnleashed = false;
                _ball.setCurrentSpeed(_ball.getBaseSpeed());
            }

            if (_defendingWallIsActive)
            {
                _ball.setAtk(0);
                _ball.isGoingRight(true);
                _ball.isGoingLeft(false);
                _ball.setCollisionWithEnemy(false);
                _ball.setCollisionWithEnemyCamp(false);              
                _defendingWallIsActive = false;
                               

            }
           
        }

        for (auto& player : _playerStorer)
        {
            if (_ball.getCollider().getGlobalBounds().intersects(player.getSprite().getGlobalBounds()))
            {
                
                _intersectCounterForPlayer++;
                if (_intersectCounterForPlayer == 1)
                {
                   // std::cout << "ball touched player" << std::endl;
                    _ball.setCollisionWithPlayer(true);
                    //_ball.getCollider().setOutlineColor(sf::Color::Black);
                    //_ball.getCollider().setFillColor(sf::Color::Transparent);
                    if (_ball.hasCollidedWithEnemy())
                    {
                        std::cout << "PLAYER IS HIT 2 " << std::endl;
                        if (_ball.getCollider().getScale().x == 5 && _ball.getCollider().getScale().y == 5)
                        {
                             
                             _ballSmallingEffectSound.play();
                             _ball.getCollider().setScale(sf::Vector2f(1, 1));
                        }
                        if (_wave == 0)
                        {
                            _explanationBallHitPlayer = true;
                            if (_explanationBallHitPlayer && !_explanationBallHitPlayerSeen)
                            {
                                _textOfExplanationBallHitPlayer.setPosition(player.getSprite().getPosition().x - 200, player.getSprite().getPosition().y + 50);
                                float  textOfExplanationBallHitPlayerX = _textOfExplanationBallHitPlayer.getPosition().x;
                                float  textOfExplanationBallHitPlayerY = _textOfExplanationBallHitPlayer.getPosition().y;
                                _theDefendingWallText.setPosition(textOfExplanationBallHitPlayerX, textOfExplanationBallHitPlayerY + 130);
                                _theGreenZoneText.setPosition(-1000, -1000);
                                _playerCampDescription.setPosition(-1000, -1000);
                                _pause = true;
                            }
                        }

                       
                        if (_reductionDamageIsUnlocked)
                        {
                            //player.getDamage(_ball.getAtk() / 2);
                            _hitEnemyEffectSound.play();
                            std::cout << "reducing damages" << std::endl;
                        }

                        else
                        {
                            //  player.getDamage(_ball.getAtk() * 0.6);
                            std::cout << "reducing damages" << std::endl;
                            _hitEnemyEffectSound.play();
                        }
                       
                        
                        
                        if (!_ball.hasCollidedWithPlayerCamp())
                        {
                            _defendingWallIsActive = true;
                        }
                        
                        _ball.setCollisionWithEnemy(false);
                        _ball.setCollisionWithEnemyCamp(false);
                    }

                    if(_ball.hasCollidedWithEnemyCamp())
                    {
                        if (_wave == 0)
                        {

                            _explanationPlayerImmune= true;
                            if (_explanationPlayerImmune&& !_explanationPlayerImmuneSeen)
                            {
                                float widthBattleArea = _settings.getWidthOfBattleAreaBorders();
                                float heighBattleArea = _settings.getHeightOfBattleAreaBorders();
                                float battleAreaX = _settings.getBattleAreaBorders().getPosition().x;
                                float battleAreaY = _settings.getBattleAreaBorders().getPosition().y;

                                _textOfExplanationPlayerImmune.setPosition(player.getSprite().getPosition().x - 100, player.getSprite().getPosition().y + 50);
                                float  textOfExplanationPlayerImmuneX = _textOfExplanationPlayerImmune.getPosition().x;
                                float  textOfExplanationPlayerImmuneY = _textOfExplanationPlayerImmune.getPosition().y;
                                _theGreenZoneText.setPosition(-1000, -1000);
                                _playerCampDescription.setPosition(-1000, -1000);
                                _pause = true;
                            }
                        }
                        _ball.setCollisionWithEnemyCamp(false);
                        _ball.setCollisionWithEnemy(false);
                        
                    }
                    
                   
                    
                    if (player.getSprite().getPosition().x < _ball.getCollider().getPosition().x && player.headingRight())
                    {                    
                        _ball.isGoingRight(true);
                        _ball.isGoingLeft(false);
                        _ball.setCurrentSpeed(_ball.getBaseSpeed() + (player.getSpeed() * 0.5));
                        if (_ball.getCurrentSpeed() >= 25.f)
                        {
                            _ball.setCurrentSpeed(25.f);
                        }
                    }
                   
                    if (player.getSprite().getPosition().x > _ball.getCollider().getPosition().x)
                    {
                        _ball.isGoingRight(false);
                        _ball.isGoingLeft(true);
                        _ball.setCurrentSpeed(_ball.getBaseSpeed());
                       
                    }

                    if (player.getSprite().getPosition().x < _ball.getCollider().getPosition().x && 
                        !player.headingRight() &&
                        !player.headingLeft() &&
                        !player.headingUp() &&
                        !player.headingDown())
                    {
                        _ball.isGoingRight(true);
                        _ball.isGoingLeft(false);
                        _ball.setCurrentSpeed(_ball.getBaseSpeed());
                    }

                    if (player.getSprite().getPosition().x == _ball.getCollider().getPosition().x)
                    {
                        std::cout << "wft" << std::endl;
                        if (_ball.headingRight() && player.headingRight())
                        {
                            _ball.isGoingRight(false);
                            _ball.isGoingLeft(true);
                            _ball.setCurrentSpeed(_ball.getBaseSpeed());
                        }

                        if (_ball.headingLeft() && player.headingRight())
                        {
                            _ball.isGoingRight(true);
                            _ball.isGoingLeft(false);
                            _ball.setCurrentSpeed(_ball.getBaseSpeed() + (player.getSpeed() * 0.5));
                            if (_ball.getCurrentSpeed() > 25.f)
                            {
                                _ball.setCurrentSpeed(25.f);
                            }
                        }

                    }

                   

                
                   
                }
            }

            if (!_ball.getCollider().getGlobalBounds().intersects(player.getSprite().getGlobalBounds()))
            {
                _intersectCounterForPlayer = 0;
            }
        }



        if (_upgradePhase)
        {
           
            //sf::Mouse::setPosition(sf::Vector2i(100,100));
            _waveIsInProgress = false;
            _defendingWallIsActive = false;
            
            if (_nbOfAbiliyPoints > 0)
            {
                _playerHasLeveledUp = true;
            }
            
            for (auto& player : _playerStorer)
            {
                if (_wave % 40 == 0 && _wave !=0)
                {
                    _playerStorer.erase(_playerStorer.begin());
                    _win = true;
                }

                
            }
            if (!_restore)
            {
                if ((_wave + 1) % 5 == 0)
                {
                    _restore = true;

                }

                else
                {
                    _restoreCounter = 0;
                }

                if (_restore)
                {
                    _restoreCounter++;
                    if (_restoreCounter == 1)
                    {
                        for (auto& player: _playerStorer)
                        {
                            std::cout << std::endl<< std::endl << std::endl << "max hp player" << player.getMaxHp() << std::endl;
                            std::cout << "player hp before heal:" << player.getHp() << std::endl;
                            float hpBeforeHeal = player.getHp();
                            //player.setHp(player.getHp() + (player.getMaxHp() / 2.f));
                            std::cout << "healing player.. restore " << player.getHp() - hpBeforeHeal << "hp" << std::endl;
                            std::cout << "player hp after heal:" << player.getHp() << std::endl;
                            
                        }
                      
                    }

                }
            }

            else
            {
               
                _restore = false;
            }         
            if (_ball.hasCollidedWithEnemy())
            {
                _ball.setCollisionWithEnemy(false);
            }
            if (_ball.hasCollidedWithEnemyCamp())
            {
                _ball.setCollisionWithEnemyCamp(false);
            }
           

           
            
            

           

            //std::cout << std::boolalpha << _ball.hasCollidedWithPlayer() << std::endl;

            
            float widthBattleArea = _settings.getWidthOfBattleAreaBorders();
            float heighBattleArea = _settings.getHeightOfBattleAreaBorders();
            float battleAreaX = _settings.getBattleAreaBorders().getPosition().x;
            float battleAreaY = _settings.getBattleAreaBorders().getPosition().y;


            _textNextWave.move(1, 0);

            if (_textNextWave.getPosition().x > battleAreaX + widthBattleArea / 2 - 200)
            {
                _textNextWave.setPosition(battleAreaX + widthBattleArea / 2 - 300, battleAreaY + 20);
            }

            float heightStoreText = _textureOfStore.getSize().y;
            float storeX = _spriteOfStore.getPosition().x;
            float storeY = _spriteOfStore.getPosition().y;

            if (_spriteOfStore.getPosition().y > (0.20 * heighBattleArea) + 1.5 * heightStoreText)
            {
                //std::cout << "woww" << std::endl;
                _spriteOfStore.setPosition((widthBattleArea * 0.95), (0.20 * heighBattleArea) + heightStoreText);
            }

            float widthHealItem = _textureOfHealItem.getSize().x;
            float heightHealItem = _textureOfHealItem.getSize().y;
            _spriteOfHealItem.setPosition(storeX, storeY + heightHealItem);
            float healItemX = _spriteOfHealItem.getPosition().x;
            float healItemY = _spriteOfHealItem.getPosition().y;
            _spriteOfBoxPriceHealItem.setPosition(healItemX, healItemY + 33); //heal item price box
            if (_money >= _priceHealItem)
            {
                _spriteOfBoxPriceHealItem.setColor(sf::Color(255, 255, 128));
            }

            else
            {
                _spriteOfBoxPriceHealItem.setColor(sf::Color(184, 184, 184));
            }

            float boxPriceHealItemX = _spriteOfBoxPriceHealItem.getPosition().x;
            float boxPriceHealItemY = _spriteOfBoxPriceHealItem.getPosition().y;
            float widthBoxPriceHealItem = _textureOfPriceBoxForItems.getSize().x;
            float heightBoxPriceHealItem = _textureOfPriceBoxForItems.getSize().y;
            _healItemPrice.setPosition(boxPriceHealItemX - _healItemPrice.getCharacterSize() / 2, boxPriceHealItemY - 20);
            _healItemPrice.setString(std::to_string(int(_priceHealItem))); //heal item price text

            float healItemPriceX = _healItemPrice.getPosition().x;
            float healItemPriceY = _healItemPrice.getPosition().y;
            float widthHealItemPriceDecoration = _textureOfMoney.getSize().x * _spriteOfHealItemPriceDecoration.getScale().x;
            float heightHealItemPriceDecoration = _textureOfMoney.getSize().y * _spriteOfHealItemPriceDecoration.getScale().y;
            _spriteOfHealItemPriceDecoration.setPosition(healItemPriceX - widthHealItemPriceDecoration, healItemPriceY + heightHealItemPriceDecoration / 2 - 5); //heal item decoration 


            float widthReductionDamageItem = _textureOfReductionDamageItem.getSize().x;
            float heightReductionDamageItem = _textureOfReductionDamageItem.getSize().y;
            _spriteOfReductionDamageItem.setPosition(storeX, storeY + 200);
            float ReductionDamageItemX = _spriteOfReductionDamageItem.getPosition().x;
            float ReductionDamageItemY = _spriteOfReductionDamageItem.getPosition().y;
            _spriteOfBoxPriceReductionDamageItem.setPosition(ReductionDamageItemX, ReductionDamageItemY + 33); //ReductionDamage item price box

            if (_money >= _priceReductionDamageItem && !_reductionDamageIsUnlocked)
            {
                _spriteOfBoxPriceReductionDamageItem.setColor(sf::Color(255, 255, 128));
            }

            else
            {
                _spriteOfBoxPriceReductionDamageItem.setColor(sf::Color(184, 184, 184));
            }

            float boxPriceReductionDamageItemX = _spriteOfBoxPriceReductionDamageItem.getPosition().x;
            float boxPriceReductionDamageItemY = _spriteOfBoxPriceReductionDamageItem.getPosition().y;
            float widthBoxPriceReductionDamageItem = _textureOfPriceBoxForItems.getSize().x;
            float heightBoxPriceReductionDamageItem = _textureOfPriceBoxForItems.getSize().y;
            _reductionDamageItemPrice.setPosition(boxPriceReductionDamageItemX - _reductionDamageItemPrice.getCharacterSize() / 2, boxPriceReductionDamageItemY - 20);
            _reductionDamageItemPrice.setString(std::to_string(int(_priceReductionDamageItem))); //ReductionDamage item price text

            float ReductionDamageItemPriceX = _reductionDamageItemPrice.getPosition().x;
            float ReductionDamageItemPriceY = _reductionDamageItemPrice.getPosition().y;
            float widthReductionDamageItemPriceDecoration = _textureOfMoney.getSize().x * _spriteOfReductionDamageItemPriceDecoration.getScale().x;
            float heightReductionDamageItemPriceDecoration = _textureOfMoney.getSize().y * _spriteOfReductionDamageItemPriceDecoration.getScale().y;
            _spriteOfReductionDamageItemPriceDecoration.setPosition(ReductionDamageItemPriceX - widthReductionDamageItemPriceDecoration, ReductionDamageItemPriceY + heightReductionDamageItemPriceDecoration / 2 - 5); //ReductionDamage item decoration 
            
            /*float widthDefendingWallItem = _textureOfDefendingWallItem.getSize().x;
            float heightDefendingWallItem = _textureOfDefendingWallItem.getSize().y;
            _spriteOfDefendingWallItem.setPosition(storeX, storeY + 300);
            float DefendingWallItemX = _spriteOfDefendingWallItem.getPosition().x;
            float DefendingWallItemY = _spriteOfDefendingWallItem.getPosition().y;
            _spriteOfBoxPriceDefendingWallItem.setPosition(DefendingWallItemX, DefendingWallItemY + 33); //defendingWall item price box

           if (_money >= _priceDefendingWallItem && !_defendingWallIsUnlocked)
            {
                _spriteOfBoxPriceDefendingWallItem.setColor(sf::Color(255, 255, 128));
            }

            else
            {
                _spriteOfBoxPriceDefendingWallItem.setColor(sf::Color(184, 184, 184));
            }

            float boxPriceDefendingWallItemX = _spriteOfBoxPriceDefendingWallItem.getPosition().x;
            float boxPriceDefendingWallItemY = _spriteOfBoxPriceDefendingWallItem.getPosition().y;
            float widthBoxPriceDefendingWallItem = _textureOfPriceBoxForItems.getSize().x;
            float heightBoxPriceDefendingWallItem = _textureOfPriceBoxForItems.getSize().y;
            _defendingWallItemPrice.setPosition(boxPriceDefendingWallItemX - _defendingWallItemPrice.getCharacterSize() / 2, boxPriceDefendingWallItemY - 20);
            _defendingWallItemPrice.setString(std::to_string(int(_priceDefendingWallItem))); //defending wall item price text

            float DefendingWallItemPriceX = _defendingWallItemPrice.getPosition().x;
            float DefendingWallItemPriceY = _defendingWallItemPrice.getPosition().y;
            float widthDefendingWallItemPriceDecoration = _textureOfMoney.getSize().x * _spriteOfDefendingWallItemPriceDecoration.getScale().x;
            float heightDefendingWallItemPriceDecoration = _textureOfMoney.getSize().y * _spriteOfDefendingWallItemPriceDecoration.getScale().y;
            _spriteOfDefendingWallItemPriceDecoration.setPosition(DefendingWallItemPriceX - widthDefendingWallItemPriceDecoration, DefendingWallItemPriceY + heightDefendingWallItemPriceDecoration / 2 - 5);*/ //defendingWall item decoration 
            
            _spriteOfIncreaseSpeed.setPosition(battleAreaX + widthBattleArea / 5, battleAreaY + heighBattleArea / 4);
            _spriteOfDashUnlocked.setPosition(battleAreaX + 160, battleAreaY + 300);
            _speedPointsText.setPosition(_spriteOfIncreaseSpeed.getPosition().x - 5, _spriteOfIncreaseSpeed.getPosition().y + 13);
           
            if (_nbSpeedPoints < 10)
            {
                _speedPointsText.setString(std::to_string(_nbSpeedPoints));
               
            }
            else
            {
                _speedPointsText.setString("MAX");
            }

            _spriteOfIncreaseAttack.setPosition(battleAreaX + widthBattleArea / 2.7, battleAreaY + heighBattleArea / 4);
            _spriteOfFlipperUnlocked.setPosition(battleAreaX + 160, battleAreaY + 300);   
            if (_nbAttackPoints < 10)
            {
                _attackPointsText.setString(std::to_string(_nbAttackPoints));
                _attackPointsText.setPosition(_spriteOfIncreaseAttack.getPosition().x - 28, _spriteOfIncreaseAttack.getPosition().y + 18);
            }
            else 
            {
                _attackPointsText.setString("MAX");
                _attackPointsText.setPosition(_spriteOfIncreaseAttack.getPosition().x - 36, _spriteOfIncreaseAttack.getPosition().y + 18);
            }
           

            _spriteOfIncreaseMaxHp.setPosition(battleAreaX + widthBattleArea / 1.8, battleAreaY + heighBattleArea / 4);
            _spriteOfRegenUnlocked.setPosition(battleAreaX + 160, battleAreaY + 300);
            _maxHpPointsText.setPosition(_spriteOfIncreaseMaxHp.getPosition().x - 9, _spriteOfIncreaseMaxHp.getPosition().y + 67);
            
            if (_nbMaxHpPoints < 10)
            {
                _maxHpPointsText.setString(std::to_string(_nbMaxHpPoints));

            }
            else
            {
                _maxHpPointsText.setString("MAX");
            }

            if (totalTimeElapsed >=200)
            {

                if (_storeTextMovingUp)
                {
                    _storeTextMovingDown = true;
                    _spriteOfStore.move(0, -2);
                }

                else if (_storeTextMovingDown)
                {
                    _spriteOfStore.move(0, 2);
                    _storeTextMovingUp = true;
                }

                _spriteOfStore.move(0, 5);

                _spriteOfIncreaseSpeed.move(0, 10);
                _speedPointsText.move(0, 10);
                _spriteOfDashUnlocked.move(0, 10);


                _spriteOfIncreaseAttack.move(0, 10);
                _attackPointsText.move(0, 10);
                _spriteOfFlipperUnlocked.move(0, 10);

                _spriteOfIncreaseMaxHp.move(0, 10);
                _maxHpPointsText.move(0, 10);
                _spriteOfRegenUnlocked.move(0, 10);
            }
          
        }
       
        updateXp();

        if (_playerHasLeveledUp)
        {
            _iLevelUp++;
            for (auto& player : _playerStorer)
            {

                if (_timerLevelUp < 2000 && _iLevelUp < 200)
                {
                    //std::cout << "yes" << std::endl;
                    //std::cout << _timerLevelUp << std::endl;

                    float playerX = 0;
                    float playerY = 0;
                    float widthPlayer = 0;
                    float heightPlayer = 0;
                    for (auto& player : _playerStorer)
                    {
                        playerX = player.getSprite().getPosition().x;
                        playerY = player.getSprite().getPosition().y;
                        widthPlayer = player.getTexture().getSize().x;
                        heightPlayer = player.getTexture().getSize().y;
                    }

                    
                    _spriteOfLevelUp.setPosition(player.getSprite().getPosition().x, player.getSprite().getPosition().y);
                    _textForLevelUp.setPosition(playerX - _textForLevelUp.getCharacterSize() - 40, playerY - heightPlayer / 2 - 50);
                    _spriteOfLevelUp.setRotation(player.getSprite().getRotation());
                    player.getLevelText().setOutlineColor(sf::Color::Green);
                    player.getHealthbar().setFillColor(sf::Color(214, 244, 68));
                    player.getHealthbar().setOutlineThickness(-1);
                    player.getHealthbar().setOutlineColor(sf::Color::White);
                    player.getSprite().setScale(1, 1);
                    player.getSprite().setColor(sf::Color());
                    


                    if (_timerLevelUp > 100)
                    {
                        player.getLevelText().setOutlineColor(sf::Color::Black);
                        player.getHealthbar().setOutlineColor(sf::Color::Black);
                        player.getSprite().setScale(1.2, 1.1);
                        player.getSprite().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, 255));
                        _spriteOfLevelUp.move(0, -2);
                        _textForLevelUp.move(0, 10);
                        player.getHealthBarEmpty().move(0, -2);
                        _timerLevelUp = 0;
                        _spriteOfLevelUp.setRotation(player.getSprite().getRotation());
                    }
                }

                else
                {
                    _spriteOfLevelUp.setPosition(-100, -100);
                    _textForLevelUp.setPosition(-100, -100);
                    player.getHealthbar().setFillColor(sf::Color::Green);
                    player.getLevelText().setOutlineColor(sf::Color::Green);
                    player.getHealthbar().setOutlineThickness(0);
                    player.getSprite().setScale(1, 1);
                    player.getSprite().setColor(sf::Color());

                }
            }
        }

        else
        {
            for (auto& player : _playerStorer)
            {
                _spriteOfLevelUp.setPosition(-100, -100);
                _textForLevelUp.setPosition(-100, -100);
                player.getHealthbar().setFillColor(sf::Color::Green);
                player.getLevelText().setOutlineColor(sf::Color::Green);
                player.getHealthbar().setOutlineThickness(0);
                player.getSprite().setScale(1, 1);
                player.getSprite().setColor(sf::Color());
            }
        }
  
           
      
		// - player attacking || ball attacking || block attacking

        //update position of enemies healthbars
		//for (auto& healthBarOfEnemy : _healthBarsOfEnemies)
        //{
           
                    //std::cout << healthBarOfEnemy.getHealthPtr()->getValue() << " ----> " << enemy.getHealthPtr()->getValue() << std::endl;
                    //TODO
                    
                    //if (enemy.getSpriteScaleX() <= 1.1f && enemy.getSpriteScaleY() <= 1.1f) // update position config of medium enemy health bar (little)
                    //{
           /* if(healthBarOfEnemy.getDamageablePtr() != nullptr)
            {
                auto enemyPtr = dynamic_cast<Enemy*>(healthBarOfEnemy.getDamageablePtr());
                float heightHealthBar = healthBarOfEnemy.getHealthBarEmpty().getSize().y;
                float heightEnemyBody = enemyPtr->getBodyTexture().getSize().y * enemyPtr->getSpriteScaleY();
                float healthBarXposition = enemyPtr->getBodySprite().getPosition().x;
                float healthBarYposition = enemyPtr->getBodySprite().getPosition().y - heightEnemyBody / 2.f - heightHealthBar / 2.f - healthBarOfEnemy.getYOffset();
               
            }

            else if (healthBarOfEnemy.getDamageablePtr() == nullptr)
            {
                std::cout << "dead budd" << std::endl;
            }
            */
            

				
       // } //update position healthbars enemies
        
        ////////////////////////ENEMIES UDPATES/////////////////////////////
                  //  }
	            //}
            //}
		//}
		//update healthBarEnemyTest
        /*float heightHealthBar = _healthBarEnemy.getHealthBarTexture().getSize().y;
        float heightEnemyBody = _enemy.getBodyTexture().getSize().y * _enemy.getSpriteScaleY();
        float healthBarXposition = _enemy.getBodySprite().getPosition().x;
        float healthBarYposition = _enemy.getBodySprite().getPosition().y - heightEnemyBody / 2.f - heightHealthBar / 2.f - _healthBarEnemy.getYOffset();
        _healthBarEnemy.getHealthBarSprite().setPosition(healthBarXposition, healthBarYposition);
        _healthBarEnemy.getHoverSprite().setPosition(healthBarXposition, healthBarYposition);
        _healthBarEnemy.getHoverSprite().setColor(_enemy.getColor()); 
        _enemy.update();*/

		
        if(totalTimeElapsed >= 200.f)
        {
            for(auto& enemy : _enemies)
            {
                if (enemy.wingsOpen())
                {
                    enemy.openWings(false);
                }
                else
                {
                    enemy.openWings(true);
                }
            }
        	totalTimeElapsed = 0.f;
        }

       
	}

	void Game::updatePositionOfHealthBarPlayer()
    { 
        for (auto& player: _playerStorer)
        {
            float heightHealthBar = player.getHealthBarEmpty().getSize().y;
            float heightPlayer = player.getTexture().getSize().y;
            float healthBarXposition = player.getSprite().getPosition().x;
            float healthBarYposition = player.getSprite().getPosition().y - heightPlayer / 2.f - heightHealthBar / 2.f - player.getYOffset();
            player.getHealthBarEmpty().setPosition(healthBarXposition, healthBarYposition);
        }
       
		
    }
	void Game::render()
{
    _settings.getGameWindow().clear(sf::Color::White);

    // draw everything.
    _settings.getGameWindow().draw(_ground);
    _settings.getGameWindow().draw(_leftWall);
    _settings.getGameWindow().draw(_rightWall);
    _settings.getGameWindow().draw(_ceiling);
    _settings.getGameWindow().draw(_settings.getGameWindowBorders());
    _settings.getGameWindow().draw(_settings.getBattleAreaBorders());

    if (_wave == 0)
    {
        _settings.getGameWindow().draw(_spriteOfDictacticielLeftMovement);
        _settings.getGameWindow().draw(_spriteOfDictacticielUpMovement);
        _settings.getGameWindow().draw(_spriteOfDictacticielDownMovement);
        if (!_upgradePhase)
        {
            _settings.getGameWindow().draw(_theGreenZoneText);
            _settings.getGameWindow().draw(_playerCampDescription);
        }
       

        if (checkPlayerEntersAnyEnemyRange())
        {
            _settings.getGameWindow().draw(_spriteOfDictacticielAttackMovement);
        }
        _settings.getGameWindow().draw(_spriteOfDictacticielRightMovement);
        if (_explanationBallHitEnemy)
        {
            _settings.getGameWindow().draw(_textOfExplanationBallHitEnemy);
        }
        if (_explanationBallHitPlayer)
        {
            _settings.getGameWindow().draw(_textOfExplanationBallHitPlayer);
            _settings.getGameWindow().draw(_theDefendingWallText);

        }
        if (_explanationBallHitDefendingWall)
        {
            _settings.getGameWindow().draw(_textOfExplanationBallHitDefendingWall);
            _settings.getGameWindow().draw(_theDefendingWallText);
        }
        if (_explanationBallHitEnemyCamp)
        {
            _settings.getGameWindow().draw(_textOfExplanationBallHitEnemyCamp);
            _settings.getGameWindow().draw(_theRedZoneText);
        }
        if (_explanationBallHitPlayerCamp)
        {
            _settings.getGameWindow().draw(_textOfExplanationBallHitPlayerCamp);
           // _settings.getGameWindow().draw(_theGreenZoneText);
        }
        if (_explanationBallHitPlayerCamp2)
        {
            _settings.getGameWindow().draw(_textOfExplanationBallHitPlayerCamp2);
            // _settings.getGameWindow().draw(_theGreenZoneText);
        }
        if (_explanationPlayerImmune)
        {
            _settings.getGameWindow().draw(_textOfExplanationPlayerImmune);
        }
        if (_explanationEnemiesTargetingPlayer)
        {
            _settings.getGameWindow().draw(_textOfExplanationEnemiesTargetingPlayer);
        }
       

       
       


       
        
    }


    //_enemy.draw(_settings.getGameWindow());
    //_healthBarEnemy.draw(_settings.getGameWindow());
   
    for (auto& enemy : _enemies)
    {
        if (enemy.getHp() > 0)
        {
            enemy.draw(_settings.getGameWindow());
        }
    }
        
    //for (auto& healthBarOfEnemy : _healthBarsOfEnemies)
    //{
      //  healthBarOfEnemy.draw(_settings.getGameWindow());
    //}
    for (auto& bloc : _blocsInStore)
    {
        bloc.draw(_settings.getGameWindow());
    }
    for (auto& bloc : _blocsInBattle)
    {
        bloc.draw(_settings.getGameWindow());
    }
    
    //_healthBarEnemy.draw(_settings.getGameWindow());
    _ball.draw(_settings.getGameWindow());
    _settings.getGameWindow().draw(_ballView);
   // _healthBarPlayer.draw(_settings.getGameWindow());

    _settings.getGameWindow().draw(_waveText);
    _settings.getGameWindow().draw(_spriteOfMoney);
    _settings.getGameWindow().draw(_moneyText);
    _settings.getGameWindow().draw(_spriteOfEmptyXpBar);
    _settings.getGameWindow().draw(_spriteOfFullXp);


    if (_playerHasLeveledUp && _upgradePhase)
    {
        _settings.getGameWindow().draw(_spriteOfIncreaseSpeed);
        _settings.getGameWindow().draw(_speedPointsText);
        if (_dashIsUnlocked && !_okButtonDashHasBeenPressed)
        {
            _settings.getGameWindow().draw(_spriteOfDashUnlocked);
        }



        _settings.getGameWindow().draw(_spriteOfIncreaseAttack);
        _settings.getGameWindow().draw(_attackPointsText);
        if (_flipperIsUnlocked && !_okButtonFlipperHasBeenPressed)
        {
            _settings.getGameWindow().draw(_spriteOfFlipperUnlocked);
        }

      

        _settings.getGameWindow().draw(_spriteOfIncreaseMaxHp);
        _settings.getGameWindow().draw(_maxHpPointsText);
        if (_regenIsUnlocked && !_okButtonRegenHasBeenPressed)
        {
            _settings.getGameWindow().draw(_spriteOfRegenUnlocked);
        }


    }

    if (_upgradePhase)
    {
        _settings.getGameWindow().draw(_spriteOfStore);

        _settings.getGameWindow().draw(_spriteOfHealItem);
        _settings.getGameWindow().draw(_spriteOfBoxPriceHealItem);
        _settings.getGameWindow().draw(_healItemPrice);
        _settings.getGameWindow().draw(_spriteOfHealItemPriceDecoration);


        _settings.getGameWindow().draw(_spriteOfReductionDamageItem);
        _settings.getGameWindow().draw(_spriteOfBoxPriceReductionDamageItem);
        _settings.getGameWindow().draw(_reductionDamageItemPrice);
        _settings.getGameWindow().draw(_spriteOfReductionDamageItemPriceDecoration);
        
       /* _settings.getGameWindow().draw(_spriteOfDefendingWallItem);
        _settings.getGameWindow().draw(_spriteOfBoxPriceDefendingWallItem);
        _settings.getGameWindow().draw(_defendingWallItemPrice);
        _settings.getGameWindow().draw(_spriteOfDefendingWallItemPriceDecoration);*/

        _settings.getGameWindow().draw(_textNextWave);
        
    }
    //_settings.getGameWindow().draw(_spriteOfLevelUpView);

    if (_startingPhase && !_waveIsInProgress)
    {
        _settings.getGameWindow().draw(_spriteOfStartingDirectionUpAndRight);
        _settings.getGameWindow().draw(_spriteOfStartingDirectionDownAndRight);
        _settings.getGameWindow().draw(_spriteOfStartingDirectionRight);

        if (_wave == 0)
        {
            _settings.getGameWindow().draw(_textAskingToPickDirection);


        }
    }

    if (_defendingWallIsActive)
    {
        _settings.getGameWindow().draw(_defendingWall);
    }
    
    for (auto& player : _playerStorer)
    {
        player.draw(_settings.getGameWindow());
    }
    
   


    _settings.getGameWindow().draw(_winText);
    _settings.getGameWindow().draw(_spriteOfWin);
    _settings.getGameWindow().draw(_gameOverText);
    _settings.getGameWindow().draw(_spriteOfGameOver);
    _settings.getGameWindow().draw(_spriteOfLevelUp);
    _settings.getGameWindow().draw(_textForLevelUp);
    _settings.getGameWindow().draw(_spriteOfPlayerHealingState);
    _settings.getGameWindow().draw(_spriteOfRestartButton);
    _settings.getGameWindow().draw(_spriteOfWelcomeScreen);
    
   
    for (auto& player : _playerStorer)
    {
        if (_wave == 0 && _waveIsInProgress
            && !player.headingDown()
            && !player.headingUp()
            && !player.headingLeft()
            && !player.headingRight())
        {

            _settings.getGameWindow().draw(_indicationForApproachingEnemies);
        }

    }
   
    if (_explanationBallHitEnemySeen && 
        _explanationBallHitPlayerSeen && 
        _explanationBallHitDefendingWallSeen && 
        _explanationBallHitEnemyCampSeen && 
        _explanationBallHitPlayerCampSeen && 
        _explanationBallHitPlayerCampSeen2 && 
        _explanationPlayerImmuneSeen && 
        _explanationEnemiesTargetingPlayerSeen && 
        _explanationReactionSpeedEnemySeen) 
    {
        _settings.getGameWindow().draw(_spriteOfPlayButton);
        
    }

    if (_wave == 0)
    {
        if (_explanationReactionSpeedEnemy)
        {
            _settings.getGameWindow().draw(_spriteOfExplanationReactionSpeedEnemy);
        }
    }



    //end the current frame
	_settings.getGameWindow().display();
}





