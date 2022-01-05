#include "AGame.h"

#include <iostream>


AGame::AGame() : _world(_gravity)
{
    _gravity.x = 0;
    _gravity.y = 9.8f;
    _world.SetGravity(_gravity);

    _fontForLevel.loadFromFile("data/Fonts/arial.ttf");
    _cursorTexture.loadFromFile("data/cursor.png");
    _cursorSprite.setTexture(_cursorTexture);
    _fontForTextLevel.loadFromFile("data/Fonts/arial.ttf");
    _fontForwave.loadFromFile("data/Fonts/arial.ttf");
    _fontForMoney.loadFromFile("data/Fonts/arial.ttf");
    _fontForLevelUp.loadFromFile("data/Fonts/ARCADECLASSIC.TTF");
    _textureOfMoney.loadFromFile("data/kymio.png");
    _textureOfEmptyXpBar.loadFromFile("data/xp.png");
    _textureOfFullXp.loadFromFile("data/xpFull.png");
    _textureOfIncreaseSpeed.loadFromFile("data/speedIncrease (2).png");
    _textureOfIncreaseAttack.loadFromFile("data/attackIncrease.png");
    _textureOfIncreaseMaxHp.loadFromFile("data/maxHpIncrease.png");
    _textureOfLevelUp.loadFromFile("data/levelUpView2.png");
    _textureOfLevelUpAttackRight.loadFromFile("data/levelUpViewPunchRight.png");
    _textureOfLevelUp4.loadFromFile("data/levelUpView4.png");
    _textureOfLevelUpAttackLeft.loadFromFile("data/levelUpViewPunchLeft.png");
    _textureOfStore.loadFromFile("data/storetext.png");
    _textureOfPriceBoxForItems.loadFromFile("data/storePrice.png");
    _textureOfHealItem.loadFromFile("data/healItem.png");
    _textureOfDashItem.loadFromFile("data/dashItem.png");
    _textureOfFlyItem.loadFromFile("data/flyItem.png");
    _textureOfGameOver.loadFromFile("data/playerGivingUp.png");
    _textureOfRestartButton.loadFromFile("data/restartButton.png");
    _textureOfPlayerBowRight.loadFromFile("data/playerBowRight.png");
    _textureOfPlayerBowLeft.loadFromFile("data/playerBowLeft.png");
    _textureOfPlayerPunchRight.loadFromFile("data/playerPunchRight.png");
    _textureOfPlayerPunchLeft.loadFromFile("data/playerPunchLeft.png");
    _textureOfArrow.loadFromFile("data/arrow.png");
    _textureOfDictacticielLeftMovement.loadFromFile("data/dictacticielLeft.png");
    _textureOfDictacticielRightMovement.loadFromFile("data/dictacticielRight.png");
    _textureOfDictacticielJumpMovement.loadFromFile("data/dictacticielJump.png");
    _textureOfDictacticielAttackMovementRed.loadFromFile("data/dictacticielAttackRed.png");
    _textureOfDictacticielAttackMovementWhite.loadFromFile("data/dictacticielAttackWhite.png");
    _textureOfDictacticielSwitchMovement.loadFromFile("data/dictacticielSwitchMode.png");
    _textureOfWin.loadFromFile("data/playerWin.png");

    if (!_mainTheme.openFromFile("data/mainTheme.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _mainTheme.play();

    if (!_gameOverTheme.openFromFile("data/gameOverTheme.ogg"))
    {
        std::cout << "oups" << std::endl;
    }

    if (!_winTheme.openFromFile("data/winTheme.ogg"))
    {
        std::cout << "oups" << std::endl;
    }

    if (!_shortRangeAttackBuffer.loadFromFile("data/attackShortRange.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _shortRangeAttack.setBuffer(_shortRangeAttackBuffer);

    if (!_longRangeAttackBuffer.loadFromFile("data/attackLongRange.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _longRangeAttack.setBuffer(_longRangeAttackBuffer);

    if (!_levelUpEffectBuffer.loadFromFile("data/levelUp.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _levelUpEffectSound.setBuffer(_levelUpEffectBuffer);

    if (!_moneySpentEffectBuffer.loadFromFile("data/moneySpent.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _moneySpentEffectSound.setBuffer(_moneySpentEffectBuffer);

    if (!_terrestrialSpawnEffectBuffer.loadFromFile("data/zombieSpawn.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _terrestrialSpawnEffectSound.setBuffer(_terrestrialSpawnEffectBuffer);
    
    if (!_flyingSpawnEffectBuffer.loadFromFile("data/birdster spawn.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _flyingSpawnEffectSound.setBuffer(_flyingSpawnEffectBuffer);

    if (!_xpGainEffectBuffer.loadFromFile("data/xpGain.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _xpGainEffectSound.setBuffer(_xpGainEffectBuffer);

    if (!_levelUpXpGainEffectBuffer.loadFromFile("data/levelUpXpGain.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _levelUpXpGainEffectSound.setBuffer(_levelUpXpGainEffectBuffer);

    if (!_dashEffectBuffer.loadFromFile("data/dash.ogg"))
    {
        std::cout << "oups" << std::endl;
    }
    _dashEffectSound.setBuffer(_dashEffectBuffer);


 
    

    _waveText.setFont(_fontForwave);
    _waveText.setCharacterSize(60);
    _waveText.setString("WAVE " + std::to_string(_wave));
    _waveText.setFillColor(sf::Color::White);
    _waveText.setOutlineColor(sf::Color::Black);
    _waveText.setOutlineThickness(10);
    _waveText.setStyle(sf::Text::Regular);
    _waveText.setPosition(_settings.getBattleAreaBorders().getPosition().x + _settings.getWidthOfBattleAreaBorders() / 2 - 2 * _waveText.getCharacterSize(), _settings.getBattleAreaBorders().getPosition().y - _waveText.getCharacterSize() - 17);

    _spriteOfMoney.setTexture(_textureOfMoney);
    float widthMoney = _textureOfMoney.getSize().x;
    float heighMoney = _textureOfMoney.getSize().y;
    _spriteOfMoney.setOrigin(widthMoney / 2, heighMoney / 2);
    _spriteOfMoney.setPosition(-100, -100);
    _moneyText.setFont(_fontForMoney);
    _moneyText.setCharacterSize(40);
    _moneyText.setString(std::to_string((int)_money));
    _moneyText.setFillColor(sf::Color::White);
    _moneyText.setOutlineColor(sf::Color::Black);
    _moneyText.setOutlineThickness(3);
    _moneyText.setStyle(sf::Text::Regular);
    _moneyText.setPosition(-100, -100);  //money UI

    _spriteOfEmptyXpBar.setTexture(_textureOfEmptyXpBar);
    float widthXp = _textureOfEmptyXpBar.getSize().x;
    float heightXp = _textureOfEmptyXpBar.getSize().y;
    _spriteOfEmptyXpBar.setOrigin(widthXp / 2, heightXp / 2);
    _spriteOfEmptyXpBar.setPosition(-100, -100);
    _spriteOfFullXp.setTexture(_textureOfFullXp);
    _spriteOfFullXp.setOrigin(widthXp / 2, heightXp / 2);
    _spriteOfEmptyXpBar.setPosition(-100, -100); //XP ui

    float widthOfIncreaseSpeed = _textureOfIncreaseSpeed.getSize().x;
    float heightOfIncreaseSpeed = _textureOfIncreaseSpeed.getSize().y;
    _spriteOfIncreaseSpeed.setTexture(_textureOfIncreaseSpeed);
    _spriteOfIncreaseSpeed.setOrigin(widthOfIncreaseSpeed / 2, heightOfIncreaseSpeed / 2);
    _spriteOfIncreaseSpeed.setPosition(-100, -100);
    _speedPointsText.setFont(_fontForTextLevel);
    _speedPointsText.setCharacterSize(15);
    _speedPointsText.setString("0");
    _speedPointsText.setFillColor(sf::Color::White);
    _speedPointsText.setOutlineColor(sf::Color(63, 72, 204));
    _speedPointsText.setOutlineThickness(4);
    _speedPointsText.setStyle(sf::Text::Regular);
    _speedPointsText.setPosition(-100, -100); // speed points

    float widthOfIncreaseAttack = _textureOfIncreaseAttack.getSize().x;
    float heightOfIncreaseAttack = _textureOfIncreaseAttack.getSize().y;
    _spriteOfIncreaseAttack.setTexture(_textureOfIncreaseAttack);
    _spriteOfIncreaseAttack.setOrigin(widthOfIncreaseAttack / 2, heightOfIncreaseAttack / 2);
    _spriteOfIncreaseAttack.setPosition(-100, -100);
    _attackPointsText.setFont(_fontForTextLevel);
    _attackPointsText.setCharacterSize(15);
    _attackPointsText.setString("0");
    _attackPointsText.setFillColor(sf::Color::White);
    _attackPointsText.setOutlineColor(sf::Color(197, 10, 52));
    _attackPointsText.setOutlineThickness(4);
    _attackPointsText.setStyle(sf::Text::Regular);
    _attackPointsText.setPosition(-100, -100); // attack points

    float widthOfIncreaseMaxHp = _textureOfIncreaseMaxHp.getSize().x;
    float heightOfIncreaseMaxHp = _textureOfIncreaseMaxHp.getSize().y;
    _spriteOfIncreaseMaxHp.setTexture(_textureOfIncreaseMaxHp);
    _spriteOfIncreaseMaxHp.setOrigin(widthOfIncreaseMaxHp / 2, heightOfIncreaseMaxHp / 2);
    _spriteOfIncreaseMaxHp.setPosition(-100, -100);
    _maxHpPointsText.setFont(_fontForTextLevel);
    _maxHpPointsText.setCharacterSize(15);
    _maxHpPointsText.setString("0");
    _maxHpPointsText.setFillColor(sf::Color::White);
    _maxHpPointsText.setOutlineColor(sf::Color(255, 176, 176));
    _maxHpPointsText.setOutlineThickness(4);
    _maxHpPointsText.setStyle(sf::Text::Regular);
    _maxHpPointsText.setPosition(-100, -100); // maxHp points

    _spriteOfLevelUp.setTexture(_textureOfLevelUp);
    float widthOfOfLevelUp = _textureOfLevelUp.getSize().x;
    float heightOfOfLevelUp = _textureOfLevelUp.getSize().y;
    _spriteOfLevelUp.setOrigin(widthOfOfLevelUp / 2, heightOfOfLevelUp / 2);
    _spriteOfLevelUp.setPosition(-100, -100);
    _textForLevelUp.setFont(_fontForLevelUp);
    _textForLevelUp.setCharacterSize(50);
    _textForLevelUp.setString("LEVEL UP!");
    _textForLevelUp.setPosition(-100, -100);
    _textForLevelUp.setFillColor(sf::Color::Black);//levelUp

    
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
    _spriteOfBoxPriceHealItem.setOrigin(widthPriceBoxHealItem/2, heightPriceBoxHealItem / 2);
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

    _spriteOfDashItem.setTexture(_textureOfDashItem);
    float widthDashItem = _textureOfDashItem.getSize().x;
    float heightDashItem = _textureOfDashItem.getSize().y;
    _spriteOfDashItem.setOrigin(widthDashItem / 2, heightDashItem / 2);
    _spriteOfDashItem.setPosition(-100, -100);//dash item

    _spriteOfBoxPriceDashItem.setTexture(_textureOfPriceBoxForItems);
    float widthPriceBoxDashItem = _textureOfPriceBoxForItems.getSize().x;
    float heightPriceBoxDashItem = _textureOfPriceBoxForItems.getSize().y;
    _spriteOfBoxPriceDashItem.setOrigin(widthPriceBoxDashItem / 2, heightPriceBoxDashItem / 2);
    _spriteOfBoxPriceDashItem.setPosition(-100, -100);
    _spriteOfBoxPriceDashItem.setColor(sf::Color(255, 255, 128)); //dash item price box

    _dashItemPrice.setFont(_fontForMoney);
    _dashItemPrice.setString("0");
    _dashItemPrice.setOutlineColor(sf::Color::Black);
    _dashItemPrice.setOutlineThickness(-3);
    _dashItemPrice.setFillColor(sf::Color::Black);
    _dashItemPrice.setPosition(-100, -100);
    _spriteOfDashItemPriceDecoration.setTexture(_textureOfMoney);
    _spriteOfDashItemPriceDecoration.setScale(0.4, 0.4);
    float widthDashItemPriceDecoration = _textureOfMoney.getSize().x * _spriteOfDashItemPriceDecoration.getScale().x;
    float heightDashItemPriceDecoration = _textureOfMoney.getSize().y * _spriteOfDashItemPriceDecoration.getScale().y;
    _spriteOfDashItemPriceDecoration.setOrigin(widthDashItemPriceDecoration / 2, heightDashItemPriceDecoration / 2);
    _spriteOfDashItemPriceDecoration.setPosition(-100, -100);
    _spriteOfDashItemPriceDecoration.setColor(sf::Color(255, 255, 128)); //store decoration dash  item

    _spriteOfFlyItem.setTexture(_textureOfFlyItem);
    float widthFlyItem = _textureOfFlyItem.getSize().x;
    float heightFlyItem = _textureOfFlyItem.getSize().y;
    _spriteOfFlyItem.setOrigin(widthFlyItem / 2, heightFlyItem / 2);
    _spriteOfFlyItem.setPosition(-100, -100);//fly item

    _spriteOfBoxPriceFlyItem.setTexture(_textureOfPriceBoxForItems);
    float widthPriceBoxFlyItem = _textureOfPriceBoxForItems.getSize().x;
    float heightPriceBoxFlyItem = _textureOfPriceBoxForItems.getSize().y;
    _spriteOfBoxPriceFlyItem.setOrigin(widthPriceBoxFlyItem / 2, heightPriceBoxFlyItem / 2);
    _spriteOfBoxPriceFlyItem.setPosition(-100, -100);
    _spriteOfBoxPriceFlyItem.setColor(sf::Color(255, 255, 128)); //fly item price box

    _FlyItemPrice.setFont(_fontForMoney);
    _FlyItemPrice.setString("0");
    _FlyItemPrice.setOutlineColor(sf::Color::Black);
    _FlyItemPrice.setOutlineThickness(-3);
    _FlyItemPrice.setFillColor(sf::Color::Black);
    _FlyItemPrice.setPosition(-100, -100);
    _spriteOfFlyItemPriceDecoration.setTexture(_textureOfMoney);
    _spriteOfFlyItemPriceDecoration.setScale(0.4, 0.4);
    float widthFlyItemPriceDecoration = _textureOfMoney.getSize().x * _spriteOfFlyItemPriceDecoration.getScale().x;
    float heightFlyItemPriceDecoration = _textureOfMoney.getSize().y * _spriteOfFlyItemPriceDecoration.getScale().y;
    _spriteOfFlyItemPriceDecoration.setOrigin(widthFlyItemPriceDecoration / 2, heightFlyItemPriceDecoration / 2);
    _spriteOfFlyItemPriceDecoration.setPosition(-100,-100);
    _spriteOfFlyItemPriceDecoration.setColor(sf::Color(255, 255, 128)); //store decoration fly  item
    
    _gameOverText.setFont(_fontForLevelUp);
    _gameOverText.setString("GAME OVER X");
    _gameOverText.setCharacterSize(100);
    _gameOverText.setPosition(-100, -100);
    _gameOverText.setFillColor(sf::Color::Black); //game over text

    _spriteOfGameOver.setTexture(_textureOfGameOver);
    float widthGameOverSprite = _textureOfGameOver.getSize().x;
    float heightGameOverSprite = _textureOfGameOver.getSize().y;
    _spriteOfGameOver.setOrigin(widthGameOverSprite / 2, heightGameOverSprite / 2);
    _spriteOfGameOver.setPosition(-100,-100);  //player giving up sprite

    _spriteOfRestartButton.setTexture(_textureOfRestartButton);
    float widthRestartButton = _textureOfRestartButton.getSize().x;
    float heightRestartButton = _textureOfRestartButton.getSize().y;
    _spriteOfRestartButton.setOrigin(widthRestartButton / 2, heightRestartButton / 2);
    _spriteOfRestartButton.setPosition(-100,-100); //restart button


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

    _spriteOfDictacticielJumpMovement.setTexture(_textureOfDictacticielJumpMovement);
    float widthJumpIndicatorDictacticiel = _textureOfDictacticielJumpMovement.getSize().x;
    float heightJumpIndicatorDictacticiel = _textureOfDictacticielJumpMovement.getSize().y;
    _spriteOfDictacticielJumpMovement.setOrigin(widthJumpIndicatorDictacticiel / 2, heightJumpIndicatorDictacticiel / 2);
    _spriteOfDictacticielJumpMovement.setPosition(battleAreaX + widthJumpIndicatorDictacticiel / 6 + widthJumpIndicatorDictacticiel /2, battleAreaY + heightJumpIndicatorDictacticiel / 2 + 218);
    

    _spriteOfDictacticielAttackMovement.setTexture(_textureOfDictacticielAttackMovementWhite);
    float widthAttackIndicatorDictacticiel = _textureOfDictacticielAttackMovementWhite.getSize().x;
    float heightAttackIndicatorDictacticiel = _textureOfDictacticielAttackMovementWhite.getSize().y;
    _spriteOfDictacticielAttackMovement.setOrigin(widthAttackIndicatorDictacticiel / 2, heightAttackIndicatorDictacticiel / 2);
    _spriteOfDictacticielAttackMovement.setPosition(battleAreaX + widthAttackIndicatorDictacticiel / 2 + 700, battleAreaY + heightAttackIndicatorDictacticiel + 300);


    _spriteOfDictacticielSwitchMovement.setTexture(_textureOfDictacticielSwitchMovement);
    float widthSwitchIndicatorDictacticiel = _textureOfDictacticielSwitchMovement.getSize().x;
    float heightSwitchIndicatorDictacticiel = _textureOfDictacticielSwitchMovement.getSize().y;
    _spriteOfDictacticielSwitchMovement.setOrigin(widthSwitchIndicatorDictacticiel / 2, heightSwitchIndicatorDictacticiel / 2);
    _spriteOfDictacticielSwitchMovement.setPosition(battleAreaX + widthSwitchIndicatorDictacticiel / 2 + 700, battleAreaY + heightSwitchIndicatorDictacticiel + 100);

    _textNextWave.setFont(_fontForLevelUp);
    _textNextWave.setFillColor(sf::Color::Black);
    _textNextWave.setPosition(battleAreaX + widthBattleArea / 2 - 300, battleAreaY + 20);
    _textNextWave.setString("press  A  to  go  next  wave"); //next wave text


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
    _ground.setPosition(groundXpos + _settings.getWidthOfBattleAreaBorders() / 2, groundBody->GetPosition().y * SCALE - _ground.getSize().y / 2);
    _ground.setFillColor(sf::Color::Green); // create ground

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
    ceilingShape.SetAsBox(_settings.getWidthOfBattleAreaBorders() / SCALE, 16 / 2 / SCALE);
    b2FixtureDef ceilingFixtureDef;
    ceilingFixtureDef.density = 1.f;
    ceilingFixtureDef.shape = &ceilingShape;
    ceilingBody->CreateFixture(&ceilingFixtureDef);
    _ceiling.setSize(sf::Vector2f(_settings.getWidthOfBattleAreaBorders(), 16));
    _ceiling.setOrigin(_ceiling.getSize().x / 2, _ceiling.getSize().y / 2);
    _ceiling.setPosition(ceilingBody->GetPosition().x * SCALE + _settings.getWidthOfBattleAreaBorders() / 2, ceilingBody->GetPosition().y * SCALE);
    _ceiling.setFillColor(sf::Color::Green); // create ceiling


    _player.getSprite().setPosition(-100, -100);
    float widthPlayer = _player.getTexture().getSize().x * _player.getSprite().getScale().x;
    float heightPlayer = _player.getTexture().getSize().y * _player.getSprite().getScale().y;
    _player.getBodyDef().position = b2Vec2(groundXpos / SCALE + widthPlayer / 2 / SCALE - _outlineThickness / SCALE, groundYpos / SCALE - heightPlayer / 2/ SCALE);
    b2Body* playerBody = _world.CreateBody(&_player.getBodyDef());
    _player.setBody(playerBody);
    _player.getBody()->CreateFixture(&_player.getFixtureDef());
    _player.getBody()->SetLinearDamping(2.f);
    _playerStorer.push_back(std::move(_player));// setup player

    _spriteOfArrow.setTexture(_textureOfArrow);
    float widthArrow = _textureOfArrow.getSize().x;
    float heightArrow = _textureOfArrow.getSize().y;
    _spriteOfArrow.setOrigin(widthArrow / 2, heightArrow / 2);
    _spriteOfArrow.setPosition(-100, -100);  //arrow

    _terrestrialEnemiesSpawnpoint.left = _settings.getBattleAreaBorders().getPosition().x + _settings.getWidthOfBattleAreaBorders();
    _terrestrialEnemiesSpawnpoint.top = _settings.getBattleAreaBorders().getPosition().y + _settings.getHeightOfBattleAreaBorders();
    _terrestrialEnemiesSpawnpoint2.left = _settings.getBattleAreaBorders().getPosition().x + (0.80f * _settings.getWidthOfBattleAreaBorders());
    _terrestrialEnemiesSpawnpoint2.top = _settings.getBattleAreaBorders().getPosition().y + _settings.getHeightOfBattleAreaBorders();

    _flyingEnemiesSpawnpoint.left = _settings.getBattleAreaBorders().getPosition().x + _settings.getWidthOfBattleAreaBorders();
    _flyingEnemiesSpawnpoint.top = _settings.getBattleAreaBorders().getPosition().y + (0.2f * _settings.getHeightOfBattleAreaBorders());
    _flyingEnemiesSpawnpointLeft.left = _settings.getBattleAreaBorders().getPosition().x + (0.2f * _settings.getWidthOfBattleAreaBorders());
    _flyingEnemiesSpawnpointLeft.top = _settings.getBattleAreaBorders().getPosition().y + (0.2f * _settings.getHeightOfBattleAreaBorders());
     std::cout << "wave: " << _wave << std::endl;
     spawnFlyingEnemy();
     spawnTerrestrialEnemy();
     _terrestrialSpawnEffectSound.play();
     _flyingSpawnEffectSound.play();
}

void AGame::updateTheXp()
{
    for (auto& player:  _playerStorer)
    {
        if (player.getCurrentXp() >= player.getXpToLevelUp())
        {
            //std::cout << "player level:" << player.getLevel() << std::endl;
            _nbOfAbiliyPoints++;
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
        }
        else
        {

            float ratioOfCurrentXp = player.getCurrentXp() / player.getXpToLevelUp();
            float heightOfXpBar = _textureOfEmptyXpBar.getSize().y * _spriteOfEmptyXpBar.getScale().y;
            float maximumWidthOfXpBar = _textureOfEmptyXpBar.getSize().x * _spriteOfEmptyXpBar.getScale().x;
            float widthOfCurrentXpBar = ratioOfCurrentXp * maximumWidthOfXpBar;
            _spriteOfFullXp.setTextureRect(sf::IntRect(0, 0, widthOfCurrentXpBar, heightOfXpBar));
            //_spriteOfLevelUpView.setPosition((-100,-100));
        }
    }
   
}

void AGame::spawnTerrestrialEnemy()
{
    /*
        TODO
        -wave < 6 -> que des petits
        - wave [6;12[ 50/50 petits et moyens
        - wave [12;20[ 2/3 moyens et 1/3 gros
        - wave [20;40{ introduction des colorés & (3/4 des gros -- 0.7/4 moyens -- 0.3/4 petits
    */
    if (_wave == 0)
    {
        //little sized
        TerrestrialEnemy enemy;
        enemy.getSprite().setScale(sf::Vector2f(0.6, 0.6));
        float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
        float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

        int randPos;
        do
        {
            randPos = 1 + rand() % 2;
        } while (randPos <= 0);

        if (randPos == 1)
        {
            enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
        }

        else if (randPos == 2)
        {
            enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint2.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint2.top / SCALE - heightEnemy / 2 / SCALE);
        }

        b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
        enemy.setBody(std::move(enemyBody));
        enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
        enemy.getBody()->SetLinearDamping(2.f);
        _terrestrialEnemies.push_back(std::move(enemy));
        _terrestrialEnemies.back().getTexture().loadFromFile("data/TerrestrialEnemyLeft.png");
        _terrestrialEnemies.back().getSprite().setTexture(_terrestrialEnemies.back().getTexture());
        _terrestrialEnemies.back().getTextureOfTerrestrialEnemyRight().loadFromFile("data/TerrestrialEnemyRight.png");
        _terrestrialEnemies.back().getLevelIndicator().setFont(_fontForLevel);

        _terrestrialEnemies.back().setBaseAtk(0);
        _terrestrialEnemies.back().setBaseMaxHp(300);
        _terrestrialEnemies.back().setBaseXpDrop(-1.1);
        _terrestrialEnemies.back().setBaseMoneyDrop(5);


        _terrestrialEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
        float alpha = static_cast<float>(_terrestrialEnemies.back().getColor().a);
        float referenceSpeed = _terrestrialEnemies.back().getBody()->GetMass() * 9.8f * 0.05f;
        _terrestrialEnemies.back().setMaxSpeed((referenceSpeed /4));
        _terrestrialEnemies.back().setMaxHp(((_terrestrialEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseMaxHp()) + (1.1 * _terrestrialEnemies.back().getLevel())));
        _terrestrialEnemies.back().setHp(_terrestrialEnemies.back().getMaxHp());
        _terrestrialEnemies.back().setMaxAtk(_terrestrialEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseAtk()) + (1.1 * _terrestrialEnemies.back().getLevel()));
        std::cout << "atk: " << _terrestrialEnemies.back().getAtk() << std::endl;
        std::cout << "hp: " << _terrestrialEnemies.back().getHp() << std::endl;
        std::cout << "speed: " << _terrestrialEnemies.back().getSpeed() << std::endl;
    }

    if (_wave < 5 && _wave > 0)
    {
        //little sized
        TerrestrialEnemy enemy;
        enemy.getSprite().setScale(sf::Vector2f(0.6, 0.6));
        float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
        float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

        int randPos;
        do
        {
            randPos = 1 + rand() % 2;
        } while (randPos <= 0);

        if (randPos == 1)
        {
            enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
        }

        else if (randPos == 2)
        {
            enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint2.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint2.top / SCALE - heightEnemy / 2 / SCALE);
        }

        b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
        enemy.setBody(std::move(enemyBody));
        enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
        enemy.getBody()->SetLinearDamping(2.f);
        _terrestrialEnemies.push_back(std::move(enemy));
        _terrestrialEnemies.back().getTexture().loadFromFile("data/TerrestrialEnemyLeft.png");
        _terrestrialEnemies.back().getSprite().setTexture(_terrestrialEnemies.back().getTexture());
        _terrestrialEnemies.back().getTextureOfTerrestrialEnemyRight().loadFromFile("data/TerrestrialEnemyRight.png");
        _terrestrialEnemies.back().getLevelIndicator().setFont(_fontForLevel);

        _terrestrialEnemies.back().setBaseAtk(5);
        _terrestrialEnemies.back().setBaseMaxHp(25);
        _terrestrialEnemies.back().setBaseXpDrop(16.5);
        _terrestrialEnemies.back().setBaseMoneyDrop(20);


        _terrestrialEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
        float alpha = static_cast<float>(_terrestrialEnemies.back().getColor().a);
        float referenceSpeed = _terrestrialEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
        if (_minAlphaInRange >= 100)
        {
            std::cout << "nice" << std::endl;
            _terrestrialEnemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
        }
        _terrestrialEnemies.back().setMaxSpeed((referenceSpeed / 1.5) + 15);
        _terrestrialEnemies.back().setMaxHp(((_terrestrialEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseMaxHp()) + (1.1 * _terrestrialEnemies.back().getLevel())));
        _terrestrialEnemies.back().setHp(_terrestrialEnemies.back().getMaxHp());
        _terrestrialEnemies.back().setMaxAtk(_terrestrialEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseAtk()) + (1.1 * _terrestrialEnemies.back().getLevel()));
        std::cout << "atk: " << _terrestrialEnemies.back().getAtk() << std::endl;
        std::cout << "hp: " << _terrestrialEnemies.back().getHp() << std::endl;
        std::cout << "speed: " << _terrestrialEnemies.back().getSpeed() << std::endl;

    }

    else if (_wave >= 5 && _wave < 12)
    {
        int rand__ = 0;
        do
        {
            rand__ = rand() % 100; //100 is arbitrary
        } while (rand__ <= 0);

        if (rand__ > 0 && rand__ < 50)
        {
            //little sized
            TerrestrialEnemy enemy;
            enemy.getSprite().setScale(sf::Vector2f(0.6, 0.6));
            float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
            float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

            int randPos;
            do
            {
                randPos = 1 + rand() % 2;
            } while (randPos <= 0);

            if (randPos == 1)
            {
                enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
            }

            else if (randPos == 2)
            {
                enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint2.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint2.top / SCALE - heightEnemy / 2 / SCALE);
            }

            b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
            enemy.setBody(std::move(enemyBody));
            enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
            enemy.getBody()->SetLinearDamping(2.f);
            _terrestrialEnemies.push_back(std::move(enemy));
            _terrestrialEnemies.back().getTexture().loadFromFile("data/TerrestrialEnemyLeft.png");
            _terrestrialEnemies.back().getSprite().setTexture(_terrestrialEnemies.back().getTexture());
            _terrestrialEnemies.back().getTextureOfTerrestrialEnemyRight().loadFromFile("data/TerrestrialEnemyRight.png");
            _terrestrialEnemies.back().getLevelIndicator().setFont(_fontForLevel);

            _terrestrialEnemies.back().setBaseAtk(5);
            _terrestrialEnemies.back().setBaseMaxHp(25);
            _terrestrialEnemies.back().setBaseXpDrop(16.5);
            _terrestrialEnemies.back().setBaseMoneyDrop(20);



            _terrestrialEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            float alpha = static_cast<float>(_terrestrialEnemies.back().getColor().a);
            float referenceSpeed = _terrestrialEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
            _terrestrialEnemies.back().setMaxSpeed((referenceSpeed / 1.5) + 15);
            _terrestrialEnemies.back().setMaxHp(((_terrestrialEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseMaxHp()) + (1.1 * _terrestrialEnemies.back().getLevel())));
            _terrestrialEnemies.back().setHp(_terrestrialEnemies.back().getMaxHp());
            _terrestrialEnemies.back().setMaxAtk(_terrestrialEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseAtk()) + (1.1 * _terrestrialEnemies.back().getLevel()));
            std::cout << "atk: " << _terrestrialEnemies.back().getAtk() << std::endl;
            std::cout << "hp: " << _terrestrialEnemies.back().getHp() << std::endl;
            std::cout << "speed: " << _terrestrialEnemies.back().getSpeed() << std::endl;
        }

        else if (rand__ >= 50 && rand__ < 100)
        {
            //medium sized
            TerrestrialEnemy enemy;
            float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
            float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

            int randPos;
            do
            {
                randPos = 1 + rand() % 2;
            } while (randPos <= 0);

            if (randPos == 1)
            {
                enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
            }

            else if (randPos == 2)
            {
                enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint2.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint2.top / SCALE - heightEnemy / 2 / SCALE);
            }

            b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
            enemy.setBody(std::move(enemyBody));
            enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
            enemy.getBody()->SetLinearDamping(2.f);
            _terrestrialEnemies.push_back(std::move(enemy));
            _terrestrialEnemies.back().getTexture().loadFromFile("data/TerrestrialEnemyLeft.png");
            _terrestrialEnemies.back().getSprite().setTexture(_terrestrialEnemies.back().getTexture());
            _terrestrialEnemies.back().getTextureOfTerrestrialEnemyRight().loadFromFile("data/TerrestrialEnemyRight.png");
            _terrestrialEnemies.back().getLevelIndicator().setFont(_fontForLevel);

            _terrestrialEnemies.back().setBaseAtk(15);
            _terrestrialEnemies.back().setBaseMaxHp(40);
            _terrestrialEnemies.back().setBaseXpDrop(28);
            _terrestrialEnemies.back().setBaseMoneyDrop(30);


            _terrestrialEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            float alpha = static_cast<float>(_terrestrialEnemies.back().getColor().a);
            float referenceSpeed = _terrestrialEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
            _terrestrialEnemies.back().setMaxSpeed((referenceSpeed / 1.5) + 15);
            _terrestrialEnemies.back().setMaxHp(((_terrestrialEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseMaxHp()) + (1.1 * _terrestrialEnemies.back().getLevel())));
            _terrestrialEnemies.back().setHp(_terrestrialEnemies.back().getMaxHp());
            _terrestrialEnemies.back().setMaxAtk(_terrestrialEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseAtk()) + (1.1 * _terrestrialEnemies.back().getLevel()));
            std::cout << "atk: " << _terrestrialEnemies.back().getAtk() << std::endl;
            std::cout << "hp: " << _terrestrialEnemies.back().getHp() << std::endl;
            std::cout << "speed: " << _terrestrialEnemies.back().getSpeed() << std::endl;

        }
    }

    else if (_wave >= 12 && _wave < 20)
    {
        int rand__ = 0;
        do
        {
            rand__ = rand() % 100; //100 is arbitrary
        } while (rand__ <= 0);

        if (rand__ > 0 && rand__ <= 68)
        {
            //medium sized
            TerrestrialEnemy enemy;
            float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
            float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

            int randPos;
            do
            {
                randPos = 1 + rand() % 2;
            } while (randPos <= 0);

            if (randPos == 1)
            {
                enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
            }

            else if (randPos == 2)
            {
                enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint2.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint2.top / SCALE - heightEnemy / 2 / SCALE);
            }

            b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
            enemy.setBody(std::move(enemyBody));
            enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
            enemy.getBody()->SetLinearDamping(2.f);
            _terrestrialEnemies.push_back(std::move(enemy));
            _terrestrialEnemies.back().getTexture().loadFromFile("data/TerrestrialEnemyLeft.png");
            _terrestrialEnemies.back().getSprite().setTexture(_terrestrialEnemies.back().getTexture());
            _terrestrialEnemies.back().getTextureOfTerrestrialEnemyRight().loadFromFile("data/TerrestrialEnemyRight.png");
            _terrestrialEnemies.back().getLevelIndicator().setFont(_fontForLevel);

            _terrestrialEnemies.back().setBaseAtk(15);
            _terrestrialEnemies.back().setBaseMaxHp(40);
            _terrestrialEnemies.back().setBaseXpDrop(28);
            _terrestrialEnemies.back().setBaseMoneyDrop(30);


            _terrestrialEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            float alpha = static_cast<float>(_terrestrialEnemies.back().getColor().a);
            float referenceSpeed = _terrestrialEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
            _terrestrialEnemies.back().setMaxSpeed((referenceSpeed / 1.5) + 15);
            _terrestrialEnemies.back().setMaxHp(((_terrestrialEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseMaxHp()) + (1.1 * _terrestrialEnemies.back().getLevel())));
            _terrestrialEnemies.back().setHp(_terrestrialEnemies.back().getMaxHp());
            _terrestrialEnemies.back().setMaxAtk(_terrestrialEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseAtk()) + (1.1 * _terrestrialEnemies.back().getLevel()));
            std::cout << "atk: " << _terrestrialEnemies.back().getAtk() << std::endl;
            std::cout << "hp: " << _terrestrialEnemies.back().getHp() << std::endl;
            std::cout << "speed: " << _terrestrialEnemies.back().getSpeed() << std::endl;
        }

        else if (rand__ > 68)
        {
            //BIG SIZED SIZED
            TerrestrialEnemy enemy;
            enemy.getSprite().setScale(1.4, 1.4);
            float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
            float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

            int randPos;
            do
            {
                randPos = 1 + rand() % 2;
            } while (randPos <= 0);

            if (randPos == 1)
            {
                enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
            }

            else if (randPos == 2)
            {
                enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint2.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint2.top / SCALE - heightEnemy / 2 / SCALE);
            }

            b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
            enemy.setBody(std::move(enemyBody));
            enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
            enemy.getBody()->SetLinearDamping(2.f);
            _terrestrialEnemies.push_back(std::move(enemy));
            _terrestrialEnemies.back().getTexture().loadFromFile("data/TerrestrialEnemyLeft.png");
            _terrestrialEnemies.back().getSprite().setTexture(_terrestrialEnemies.back().getTexture());
            _terrestrialEnemies.back().getTextureOfTerrestrialEnemyRight().loadFromFile("data/TerrestrialEnemyRight.png");
            _terrestrialEnemies.back().getLevelIndicator().setFont(_fontForLevel);

            _terrestrialEnemies.back().setBaseAtk(30);
            _terrestrialEnemies.back().setBaseMaxHp(80);
            _terrestrialEnemies.back().setBaseXpDrop(50);
            _terrestrialEnemies.back().setBaseMoneyDrop(60);


            _terrestrialEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            float alpha = static_cast<float>(_terrestrialEnemies.back().getColor().a);
            float referenceSpeed = _terrestrialEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
            _terrestrialEnemies.back().setMaxSpeed((referenceSpeed / 1.5) + 15);
            _terrestrialEnemies.back().setMaxHp(((_terrestrialEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseMaxHp()) + (1.1 * _terrestrialEnemies.back().getLevel())));
            _terrestrialEnemies.back().setHp(_terrestrialEnemies.back().getMaxHp());
            _terrestrialEnemies.back().setMaxAtk(_terrestrialEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseAtk()) + (1.1 * _terrestrialEnemies.back().getLevel()));
            std::cout << "atk: " << _terrestrialEnemies.back().getAtk() << std::endl;
            std::cout << "hp: " << _terrestrialEnemies.back().getHp() << std::endl;
            std::cout << "speed: " << _terrestrialEnemies.back().getSpeed() << std::endl;
        }



    }

    else if (_wave >= 20 && _wave < 40)
    {
        int rand__ = 0;
        do
        {
            rand__ = rand() % 100; //100 is arbitrary
        } while (rand__ <= 0);

        if (rand__ > 0 && rand__ <= 75)
        {
            //BIG SIZED SIZED
            TerrestrialEnemy enemy;
            enemy.getSprite().setScale(1.4, 1.4);
            float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
            float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

            int randPos;
            do
            {
                randPos = 1 + rand() % 2;
            } while (randPos <= 0);

            if (randPos == 1)
            {
                enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
            }

            else if (randPos == 2)
            {
                enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint2.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint2.top / SCALE - heightEnemy / 2 / SCALE);
            }

            b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
            enemy.setBody(std::move(enemyBody));
            enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
            enemy.getBody()->SetLinearDamping(2.f);
            _terrestrialEnemies.push_back(std::move(enemy));
            _terrestrialEnemies.back().getTexture().loadFromFile("data/TerrestrialEnemyLeft.png");
            _terrestrialEnemies.back().getSprite().setTexture(_terrestrialEnemies.back().getTexture());
            _terrestrialEnemies.back().getTextureOfTerrestrialEnemyRight().loadFromFile("data/TerrestrialEnemyRight.png");
            _terrestrialEnemies.back().getLevelIndicator().setFont(_fontForLevel);

            _terrestrialEnemies.back().setBaseAtk(30);
            _terrestrialEnemies.back().setBaseMaxHp(80);
            _terrestrialEnemies.back().setBaseXpDrop(50);
            _terrestrialEnemies.back().setBaseMoneyDrop(60);


            _terrestrialEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            float alpha = static_cast<float>(_terrestrialEnemies.back().getColor().a);
            float referenceSpeed = _terrestrialEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
            if (_minAlphaInRange >= 100)
            {
                std::cout << "nice" << std::endl;
                _terrestrialEnemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            }
            _terrestrialEnemies.back().setMaxSpeed((referenceSpeed / 1.5) + 15);
            _terrestrialEnemies.back().setMaxHp(((_terrestrialEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseMaxHp()) + (1.1 * _terrestrialEnemies.back().getLevel())));
            _terrestrialEnemies.back().setHp(_terrestrialEnemies.back().getMaxHp());
            _terrestrialEnemies.back().setMaxAtk(_terrestrialEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseAtk()) + (1.1 * _terrestrialEnemies.back().getLevel()));
            std::cout << "atk: " << _terrestrialEnemies.back().getAtk() << std::endl;
            std::cout << "hp: " << _terrestrialEnemies.back().getHp() << std::endl;
            std::cout << "speed: " << _terrestrialEnemies.back().getSpeed() << std::endl;
        }

        else if (rand__ > 75 && rand__ < 93)
        {
            //medium sized
            TerrestrialEnemy enemy;
            float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
            float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

            int randPos;
            do
            {
                randPos = 1 + rand() % 2;
            } while (randPos <= 0);

            if (randPos == 1)
            {
                enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
            }

            else if (randPos == 2)
            {
                enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint2.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint2.top / SCALE - heightEnemy / 2 / SCALE);
            }

            b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
            enemy.setBody(std::move(enemyBody));
            enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
            enemy.getBody()->SetLinearDamping(2.f);
            _terrestrialEnemies.push_back(std::move(enemy));
            _terrestrialEnemies.back().getTexture().loadFromFile("data/TerrestrialEnemyLeft.png");
            _terrestrialEnemies.back().getSprite().setTexture(_terrestrialEnemies.back().getTexture());
            _terrestrialEnemies.back().getTextureOfTerrestrialEnemyRight().loadFromFile("data/TerrestrialEnemyRight.png");
            _terrestrialEnemies.back().getLevelIndicator().setFont(_fontForLevel);

            _terrestrialEnemies.back().setBaseAtk(15);
            _terrestrialEnemies.back().setBaseMaxHp(40);
            _terrestrialEnemies.back().setBaseXpDrop(28);
            _terrestrialEnemies.back().setBaseMoneyDrop(30);


            _terrestrialEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            float alpha = static_cast<float>(_terrestrialEnemies.back().getColor().a);
            float referenceSpeed = _terrestrialEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
            if (_minAlphaInRange >= 100)
            {
                std::cout << "nice" << std::endl;
                _terrestrialEnemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            }
            _terrestrialEnemies.back().setMaxSpeed((referenceSpeed / 1.5) + 15);
            _terrestrialEnemies.back().setMaxHp(((_terrestrialEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseMaxHp()) + (1.1 * _terrestrialEnemies.back().getLevel())));
            _terrestrialEnemies.back().setHp(_terrestrialEnemies.back().getMaxHp());
            _terrestrialEnemies.back().setMaxAtk(_terrestrialEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseAtk()) + (1.1 * _terrestrialEnemies.back().getLevel()));
            std::cout << "atk: " << _terrestrialEnemies.back().getAtk() << std::endl;
            std::cout << "hp: " << _terrestrialEnemies.back().getHp() << std::endl;
            std::cout << "speed: " << _terrestrialEnemies.back().getSpeed() << std::endl;
        }

        else
        {
            //little sized
            TerrestrialEnemy enemy;
            enemy.getSprite().setScale(sf::Vector2f(0.6, 0.6));
            float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
            float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

            int randPos;
            do
            {
                randPos = 1 + rand() % 2;
            } while (randPos <= 0);

            if (randPos == 1)
            {
                enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
            }

            else if (randPos == 2)
            {
                enemy.getBodyDef().position = b2Vec2(_terrestrialEnemiesSpawnpoint2.left / SCALE - widthEnemy / 2 / SCALE, _terrestrialEnemiesSpawnpoint2.top / SCALE - heightEnemy / 2 / SCALE);
            }

            b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
            enemy.setBody(std::move(enemyBody));
            enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
            enemy.getBody()->SetLinearDamping(2.f);
            _terrestrialEnemies.push_back(std::move(enemy));
            _terrestrialEnemies.back().getTexture().loadFromFile("data/TerrestrialEnemyLeft.png");
            _terrestrialEnemies.back().getSprite().setTexture(_terrestrialEnemies.back().getTexture());
            _terrestrialEnemies.back().getTextureOfTerrestrialEnemyRight().loadFromFile("data/TerrestrialEnemyRight.png");
            _terrestrialEnemies.back().getLevelIndicator().setFont(_fontForLevel);

            _terrestrialEnemies.back().setBaseAtk(5);
            _terrestrialEnemies.back().setBaseMaxHp(25);
            _terrestrialEnemies.back().setBaseXpDrop(16.5);
            _terrestrialEnemies.back().setBaseMoneyDrop(20);


            _terrestrialEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            float alpha = static_cast<float>(_terrestrialEnemies.back().getColor().a);
            float referenceSpeed = _terrestrialEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
            if (_minAlphaInRange >= 100)
            {
                std::cout << "nice" << std::endl;
                _terrestrialEnemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            }
            _terrestrialEnemies.back().setMaxSpeed((referenceSpeed / 1.5) + 15);
            _terrestrialEnemies.back().setMaxHp(((_terrestrialEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseMaxHp()) + (1.1 * _terrestrialEnemies.back().getLevel())));
            _terrestrialEnemies.back().setHp(_terrestrialEnemies.back().getMaxHp());
            _terrestrialEnemies.back().setMaxAtk(_terrestrialEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _terrestrialEnemies.back().getBaseAtk()) + (1.1 * _terrestrialEnemies.back().getLevel()));
            std::cout << "atk: " << _terrestrialEnemies.back().getAtk() << std::endl;
            std::cout << "hp: " << _terrestrialEnemies.back().getHp() << std::endl;
            std::cout << "speed: " << _terrestrialEnemies.back().getSpeed() << std::endl;
        }
    }
   
}

void AGame::spawnFlyingEnemy()
{
    /*
       TODO
       -wave < 6 -> que des petits
       - wave [6;12[ 50/50 petits et moyens
       - wave [12;20[ 2/3 moyens et 1/3 gros
       - wave [20;40{ introduction des colorés & (3/4 des gros -- 0.7/4 moyens -- 0.3/4 petits
   */
    if (_wave == 0)
    {
        //little sized
        FlyingEnemy enemy;
        enemy.getSprite().setScale(sf::Vector2f(0.6, 0.6));
        float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
        float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

        int randPos;
        do
        {
            randPos = 1 + rand() % 2;
        } while (randPos <= 0);

        if (randPos == 1)
        {
            enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
        }

        else if (randPos == 2)
        {
            enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpointLeft.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpointLeft.top / SCALE - heightEnemy / 2 / SCALE);
        }

        b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
        enemy.setBody(std::move(enemyBody));
        enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
        enemy.getBody()->SetLinearDamping(2.f);
        _flyingEnemies.push_back(std::move(enemy));
        _flyingEnemies.back().getTexture().loadFromFile("data/flyingEnemyLeft.png");
        _flyingEnemies.back().getSprite().setTexture(_flyingEnemies.back().getTexture());
        _flyingEnemies.back().getTextureOfFlyingEnemyRight().loadFromFile("data/flyingEnemyRight.png");
        _flyingEnemies.back().getLevelIndicator().setFont(_fontForLevel);

        _flyingEnemies.back().setBaseAtk(0);
        _flyingEnemies.back().setBaseMaxHp(300);
        _flyingEnemies.back().setBaseXpDrop(-1.1);
        _flyingEnemies.back().setBaseMoneyDrop(5);



        _flyingEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
        float alpha = static_cast<float>(_flyingEnemies.back().getColor().a);
        float referenceSpeed = _flyingEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
        _flyingEnemies.back().setMaxSpeed((referenceSpeed / 2) + 10);
        _flyingEnemies.back().setMaxHp(((_flyingEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseMaxHp()) + (1.1 * _flyingEnemies.back().getLevel())));
        _flyingEnemies.back().setHp(_flyingEnemies.back().getMaxHp());
        _flyingEnemies.back().setMaxAtk(_flyingEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseAtk()) + (1.1 * _flyingEnemies.back().getLevel()));
        std::cout << "atk: " << _flyingEnemies.back().getAtk() << std::endl;
        std::cout << "hp: " << _flyingEnemies.back().getHp() << std::endl;
        std::cout << "speed: " << _flyingEnemies.back().getSpeed() << std::endl;
    }
    if (_wave < 5 && _wave > 0)
    {
        //little sized
        FlyingEnemy enemy;
        enemy.getSprite().setScale(sf::Vector2f(0.6, 0.6));
        float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
        float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

        int randPos;
        do
        {
            randPos = 1 + rand() % 2;
        } while (randPos <= 0);

        if (randPos == 1)
        {
            enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
        }

        else if (randPos == 2)
        {
            enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpointLeft.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpointLeft.top / SCALE - heightEnemy / 2 / SCALE);
        }

        b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
        enemy.setBody(std::move(enemyBody));
        enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
        enemy.getBody()->SetLinearDamping(2.f);
        _flyingEnemies.push_back(std::move(enemy));
        _flyingEnemies.back().getTexture().loadFromFile("data/flyingEnemyLeft.png");
        _flyingEnemies.back().getSprite().setTexture(_flyingEnemies.back().getTexture());
        _flyingEnemies.back().getTextureOfFlyingEnemyRight().loadFromFile("data/flyingEnemyRight.png");
        _flyingEnemies.back().getLevelIndicator().setFont(_fontForLevel);

        _flyingEnemies.back().setBaseAtk(5);
        _flyingEnemies.back().setBaseMaxHp(25);
        _flyingEnemies.back().setBaseXpDrop(16.5);
        _flyingEnemies.back().setBaseMoneyDrop(20);



        _flyingEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
        float alpha = static_cast<float>(_flyingEnemies.back().getColor().a);
        float referenceSpeed = _flyingEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
        _flyingEnemies.back().setMaxSpeed((referenceSpeed / 5));
        _flyingEnemies.back().setMaxHp(((_flyingEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseMaxHp()) + (1.1 * _flyingEnemies.back().getLevel())));
        _flyingEnemies.back().setHp(_flyingEnemies.back().getMaxHp());
        _flyingEnemies.back().setMaxAtk(_flyingEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseAtk()) + (1.1 * _flyingEnemies.back().getLevel()));
        std::cout << "atk: " << _flyingEnemies.back().getAtk() << std::endl;
        std::cout << "hp: " << _flyingEnemies.back().getHp() << std::endl;
        std::cout << "speed: " << _flyingEnemies.back().getSpeed() << std::endl;

    }

    else if (_wave >= 5 && _wave < 12)
    {
        int rand__ = 0;
        do
        {
            rand__ = rand() % 100; //100 is arbitrary
        } while (rand__ <= 0);

        if (rand__ > 0 && rand__ < 50)
        {
            //little sized
            FlyingEnemy enemy;
            enemy.getSprite().setScale(sf::Vector2f(0.6, 0.6));
            float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
            float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

            int randPos;
            do
            {
                randPos = 1 + rand() % 2;
            } while (randPos <= 0);

            if (randPos == 1)
            {
                enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
            }

            else if (randPos == 2)
            {
                enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpointLeft.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpointLeft.top / SCALE - heightEnemy / 2 / SCALE);
            }

            b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
            enemy.setBody(std::move(enemyBody));
            enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
            enemy.getBody()->SetLinearDamping(2.f);
            _flyingEnemies.push_back(std::move(enemy));
            _flyingEnemies.back().getTexture().loadFromFile("data/flyingEnemyLeft.png");
            _flyingEnemies.back().getSprite().setTexture(_flyingEnemies.back().getTexture());
            _flyingEnemies.back().getTextureOfFlyingEnemyRight().loadFromFile("data/flyingEnemyRight.png");
            _flyingEnemies.back().getLevelIndicator().setFont(_fontForLevel);

            _flyingEnemies.back().setBaseAtk(5);
            _flyingEnemies.back().setBaseMaxHp(25);
            _flyingEnemies.back().setBaseXpDrop(16.5);
            _flyingEnemies.back().setBaseXpDrop(16.5);
            _flyingEnemies.back().setBaseMoneyDrop(20);


            _flyingEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            float alpha = static_cast<float>(_flyingEnemies.back().getColor().a);
            float referenceSpeed = _flyingEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
            _flyingEnemies.back().setMaxSpeed((referenceSpeed / 2) + 10);
            _flyingEnemies.back().setMaxHp(((_flyingEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseMaxHp()) + (1.1 * _flyingEnemies.back().getLevel())));
            _flyingEnemies.back().setHp(_flyingEnemies.back().getMaxHp());
            _flyingEnemies.back().setMaxAtk(_flyingEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseAtk()) + (1.1 * _flyingEnemies.back().getLevel()));
            std::cout << "atk: " << _flyingEnemies.back().getAtk() << std::endl;
            std::cout << "hp: " << _flyingEnemies.back().getHp() << std::endl;
            std::cout << "speed: " << _flyingEnemies.back().getSpeed() << std::endl;
        }

        else if (rand__ >= 50 && rand__ < 100)
        {
            //medium sized
            FlyingEnemy enemy;
            float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
            float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

            int randPos;
            do
            {
                randPos = 1 + rand() % 2;
            } while (randPos <= 0);

            if (randPos == 1)
            {
                enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
            }

            else if (randPos == 2)
            {
                enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpointLeft.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpointLeft.top / SCALE - heightEnemy / 2 / SCALE);
            }

            b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
            enemy.setBody(std::move(enemyBody));
            enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
            enemy.getBody()->SetLinearDamping(2.f);
            _flyingEnemies.push_back(std::move(enemy));
            _flyingEnemies.back().getTexture().loadFromFile("data/flyingEnemyLeft.png");
            _flyingEnemies.back().getSprite().setTexture(_flyingEnemies.back().getTexture());
            _flyingEnemies.back().getTextureOfFlyingEnemyRight().loadFromFile("data/flyingEnemyRight.png");
            _flyingEnemies.back().getLevelIndicator().setFont(_fontForLevel);

            _flyingEnemies.back().setBaseAtk(15);
            _flyingEnemies.back().setBaseMaxHp(40);
            _flyingEnemies.back().setBaseXpDrop(28);
            _flyingEnemies.back().setBaseMoneyDrop(30);


            _flyingEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            float alpha = static_cast<float>(_flyingEnemies.back().getColor().a);
            float referenceSpeed = _flyingEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
            _flyingEnemies.back().setMaxSpeed((referenceSpeed / 2) + 10);
            _flyingEnemies.back().setMaxHp(((_flyingEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseMaxHp()) + (1.1 * _flyingEnemies.back().getLevel())));
            _flyingEnemies.back().setHp(_flyingEnemies.back().getMaxHp());
            _flyingEnemies.back().setMaxAtk(_flyingEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseAtk()) + (1.1 * _flyingEnemies.back().getLevel()));
            std::cout << "atk: " << _flyingEnemies.back().getAtk() << std::endl;
            std::cout << "hp: " << _flyingEnemies.back().getHp() << std::endl;
            std::cout << "speed: " << _flyingEnemies.back().getSpeed() << std::endl;

        }
    }
  
    else if (_wave >= 12 && _wave < 20)
    {
        int rand__ = 0;
        do
        {
            rand__ = rand() % 100; //100 is arbitrary
        } while (rand__ <= 0);

        if (rand__ > 0 && rand__ <= 68)
        {
            //medium sized
            FlyingEnemy enemy;
            float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
            float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

            int randPos;
            do
            {
                randPos = 1 + rand() % 2;
            } while (randPos <= 0);

            if (randPos == 1)
            {
                enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
            }

            else if (randPos == 2)
            {
                enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpointLeft.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpointLeft.top / SCALE - heightEnemy / 2 / SCALE);
            }

            b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
            enemy.setBody(std::move(enemyBody));
            enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
            enemy.getBody()->SetLinearDamping(2.f);
            _flyingEnemies.push_back(std::move(enemy));
            _flyingEnemies.back().getTexture().loadFromFile("data/flyingEnemyLeft.png");
            _flyingEnemies.back().getSprite().setTexture(_flyingEnemies.back().getTexture());
            _flyingEnemies.back().getTextureOfFlyingEnemyRight().loadFromFile("data/flyingEnemyRight.png");
            _flyingEnemies.back().getLevelIndicator().setFont(_fontForLevel);

            _flyingEnemies.back().setBaseAtk(15);
            _flyingEnemies.back().setBaseMaxHp(40);
            _flyingEnemies.back().setBaseXpDrop(28);
            _flyingEnemies.back().setBaseMoneyDrop(30);


            _flyingEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            float alpha = static_cast<float>(_flyingEnemies.back().getColor().a);
            float referenceSpeed = _flyingEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
            _flyingEnemies.back().setMaxSpeed((referenceSpeed / 2) + 10);
            _flyingEnemies.back().setMaxHp(((_flyingEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseMaxHp()) + (1.1 * _flyingEnemies.back().getLevel())));
            _flyingEnemies.back().setHp(_flyingEnemies.back().getMaxHp());
            _flyingEnemies.back().setMaxAtk(_flyingEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseAtk()) + (1.1 * _flyingEnemies.back().getLevel()));
            std::cout << "atk: " << _flyingEnemies.back().getAtk() << std::endl;
            std::cout << "hp: " << _flyingEnemies.back().getHp() << std::endl;
            std::cout << "speed: " << _flyingEnemies.back().getSpeed() << std::endl;
        }

        else if (rand__ > 68)
        {
            //big sized sized
            FlyingEnemy enemy;
            float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
            float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

            int randPos;
            do
            {
                randPos = 1 + rand() % 2;
            } while (randPos <= 0);

            if (randPos == 1)
            {
                enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
            }

            else if (randPos == 2)
            {
                enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpointLeft.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpointLeft.top / SCALE - heightEnemy / 2 / SCALE);
            }

            b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
            enemy.setBody(std::move(enemyBody));
            enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
            enemy.getBody()->SetLinearDamping(2.f);
            _flyingEnemies.push_back(std::move(enemy));
            _flyingEnemies.back().getTexture().loadFromFile("data/flyingEnemyLeft.png");
            _flyingEnemies.back().getSprite().setTexture(_flyingEnemies.back().getTexture());
            _flyingEnemies.back().getTextureOfFlyingEnemyRight().loadFromFile("data/flyingEnemyRight.png");
            _flyingEnemies.back().getLevelIndicator().setFont(_fontForLevel);

            _flyingEnemies.back().setBaseAtk(30);
            _flyingEnemies.back().setBaseMaxHp(57);
            _flyingEnemies.back().setBaseXpDrop(57);
            _flyingEnemies.back().setBaseMoneyDrop(60);


            _flyingEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            float alpha = static_cast<float>(_flyingEnemies.back().getColor().a);
            float referenceSpeed = _flyingEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
            _flyingEnemies.back().setMaxSpeed((referenceSpeed / 2) + 10);
            _flyingEnemies.back().setMaxHp(((_flyingEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseMaxHp()) + (1.1 * _flyingEnemies.back().getLevel())));
            _flyingEnemies.back().setHp(_flyingEnemies.back().getMaxHp());
            _flyingEnemies.back().setMaxAtk(_flyingEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseAtk()) + (1.1 * _flyingEnemies.back().getLevel()));
            std::cout << "atk: " << _flyingEnemies.back().getAtk() << std::endl;
            std::cout << "hp: " << _flyingEnemies.back().getHp() << std::endl;
            std::cout << "speed: " << _flyingEnemies.back().getSpeed() << std::endl;
        }

    }

    else if (_wave >= 20 && _wave < 40)
    {
        int rand__ = 0;
        do
        {
            rand__ = rand() % 100; //100 is arbitrary
        } while (rand__ <= 0);

        if (rand__ > 0 && rand__ <= 75)
        {
            //big sized sized
            FlyingEnemy enemy;
            float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
            float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

            int randPos;
            do
            {
                randPos = 1 + rand() % 2;
            } while (randPos <= 0);

            if (randPos == 1)
            {
                enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
            }

            else if (randPos == 2)
            {
                enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpointLeft.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpointLeft.top / SCALE - heightEnemy / 2 / SCALE);
            }

            b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
            enemy.setBody(std::move(enemyBody));
            enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
            enemy.getBody()->SetLinearDamping(2.f);
            _flyingEnemies.push_back(std::move(enemy));
            _flyingEnemies.back().getTexture().loadFromFile("data/flyingEnemyLeft.png");
            _flyingEnemies.back().getSprite().setTexture(_flyingEnemies.back().getTexture());
            _flyingEnemies.back().getTextureOfFlyingEnemyRight().loadFromFile("data/flyingEnemyRight.png");
            _flyingEnemies.back().getLevelIndicator().setFont(_fontForLevel);

            _flyingEnemies.back().setBaseAtk(30);
            _flyingEnemies.back().setBaseMaxHp(57);
            _flyingEnemies.back().setBaseXpDrop(57);
            _flyingEnemies.back().setBaseMoneyDrop(60);


            _flyingEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            float alpha = static_cast<float>(_flyingEnemies.back().getColor().a);
            float referenceSpeed = _flyingEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
            if (_minAlphaInRange >= 100)
            {
                std::cout << "nice" << std::endl;
                _flyingEnemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            }
            _flyingEnemies.back().setMaxSpeed((referenceSpeed / 2) + 10);
            _flyingEnemies.back().setMaxHp(((_flyingEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseMaxHp()) + (1.1 * _flyingEnemies.back().getLevel())));
            _flyingEnemies.back().setHp(_flyingEnemies.back().getMaxHp());
            _flyingEnemies.back().setMaxAtk(_flyingEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseAtk()) + (1.1 * _flyingEnemies.back().getLevel()));
            std::cout << "atk: " << _flyingEnemies.back().getAtk() << std::endl;
            std::cout << "hp: " << _flyingEnemies.back().getHp() << std::endl;
            std::cout << "speed: " << _flyingEnemies.back().getSpeed() << std::endl;
        }

        else if (rand__ > 75 && rand__ < 93)
        {
            //medium sized
            FlyingEnemy enemy;
            float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
            float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

            int randPos;
            do
            {
                randPos = 1 + rand() % 2;
            } while (randPos <= 0);

            if (randPos == 1)
            {
                enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
            }

            else if (randPos == 2)
            {
                enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpointLeft.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpointLeft.top / SCALE - heightEnemy / 2 / SCALE);
            }

            b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
            enemy.setBody(std::move(enemyBody));
            enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
            enemy.getBody()->SetLinearDamping(2.f);
            _flyingEnemies.push_back(std::move(enemy));
            _flyingEnemies.back().getTexture().loadFromFile("data/flyingEnemyLeft.png");
            _flyingEnemies.back().getSprite().setTexture(_flyingEnemies.back().getTexture());
            _flyingEnemies.back().getTextureOfFlyingEnemyRight().loadFromFile("data/flyingEnemyRight.png");
            _flyingEnemies.back().getLevelIndicator().setFont(_fontForLevel);

            _flyingEnemies.back().setBaseAtk(15);
            _flyingEnemies.back().setBaseMaxHp(40);
            _flyingEnemies.back().setBaseXpDrop(28);
            _flyingEnemies.back().setBaseMoneyDrop(30);


            _flyingEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            float alpha = static_cast<float>(_flyingEnemies.back().getColor().a);
            float referenceSpeed = _flyingEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
            if (_minAlphaInRange >= 100)
            {
                std::cout << "nice" << std::endl;
                _flyingEnemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            }
            _flyingEnemies.back().setMaxSpeed((referenceSpeed / 2) + 10);
            _flyingEnemies.back().setMaxHp(((_flyingEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseMaxHp()) + (1.1 * _flyingEnemies.back().getLevel())));
            _flyingEnemies.back().setHp(_flyingEnemies.back().getMaxHp());
            _flyingEnemies.back().setMaxAtk(_flyingEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseAtk()) + (1.1 * _flyingEnemies.back().getLevel()));
            std::cout << "atk: " << _flyingEnemies.back().getAtk() << std::endl;
            std::cout << "hp: " << _flyingEnemies.back().getHp() << std::endl;
            std::cout << "speed: " << _flyingEnemies.back().getSpeed() << std::endl;
        }

        else
        {
             //little sized
            FlyingEnemy enemy;
            enemy.getSprite().setScale(sf::Vector2f(0.6, 0.6));
            float widthEnemy = enemy.getTexture().getSize().x * enemy.getSprite().getScale().x;
            float heightEnemy = enemy.getTexture().getSize().y * enemy.getSprite().getScale().y;

            int randPos;
            do
            {
                randPos = 1 + rand() % 2;
            } while (randPos <= 0);

            if (randPos == 1)
            {
                enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpoint.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpoint.top / SCALE - heightEnemy / 2 / SCALE);
            }

            else if (randPos == 2)
            {
                enemy.getBodyDef().position = b2Vec2(_flyingEnemiesSpawnpointLeft.left / SCALE - widthEnemy / 2 / SCALE, _flyingEnemiesSpawnpointLeft.top / SCALE - heightEnemy / 2 / SCALE);
            }

            b2Body* enemyBody = _world.CreateBody(&enemy.getBodyDef());
            enemy.setBody(std::move(enemyBody));
            enemy.getBody()->CreateFixture(&enemy.getFixtureDef());
            enemy.getBody()->SetLinearDamping(2.f);
            _flyingEnemies.push_back(std::move(enemy));
            _flyingEnemies.back().getTexture().loadFromFile("data/flyingEnemyLeft.png");
            _flyingEnemies.back().getSprite().setTexture(_flyingEnemies.back().getTexture());
            _flyingEnemies.back().getTextureOfFlyingEnemyRight().loadFromFile("data/flyingEnemyRight.png");
            _flyingEnemies.back().getLevelIndicator().setFont(_fontForLevel);

            _flyingEnemies.back().setBaseAtk(5);
            _flyingEnemies.back().setBaseMaxHp(25);
            _flyingEnemies.back().setBaseXpDrop(16.5);
            _flyingEnemies.back().setBaseMoneyDrop(20);


            _flyingEnemies.back().setColor(sf::Color(255, 255, 255, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            float alpha = static_cast<float>(_flyingEnemies.back().getColor().a);
            float referenceSpeed = _flyingEnemies.back().getBody()->GetMass() * 9.8f * 0.01f;
            if (_minAlphaInRange >= 100)
            {
                std::cout << "nice" << std::endl;
                _flyingEnemies.back().setColor(sf::Color(100 + rand() % 156, 100 + rand() % 156, 100 + rand() % 156, _minAlphaInRange + rand() % (_maxAlphaInRange - _minAlphaInRange + 1)));
            }
            _flyingEnemies.back().setMaxSpeed((referenceSpeed / 2) + 10);
            _flyingEnemies.back().setMaxHp(((_flyingEnemies.back().getBaseMaxHp()) + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseMaxHp()) + (1.1 * _flyingEnemies.back().getLevel())));
            _flyingEnemies.back().setHp(_flyingEnemies.back().getMaxHp());
            _flyingEnemies.back().setMaxAtk(_flyingEnemies.back().getBaseAtk() + (alpha / _ultimateAlpha * _flyingEnemies.back().getBaseAtk()) + (1.1 * _flyingEnemies.back().getLevel()));
            std::cout << "atk: " << _flyingEnemies.back().getAtk() << std::endl;
            std::cout << "hp: " << _flyingEnemies.back().getHp() << std::endl;
            std::cout << "speed: " << _flyingEnemies.back().getSpeed() << std::endl;
         }

    }
}

void AGame::gameOver()
{
    _settings.getGameWindow().setMouseCursorVisible(true);
    if (_mainTheme.getStatus() == 2)
    {
        _mainTheme.stop();
    }

    if (_gameOverTheme.getStatus() != 2)
    {
        _gameOverTheme.play();
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

   
    
    for (auto& enemy : _flyingEnemies)
    {
        std::vector<FlyingEnemy>::iterator it = _flyingEnemies.begin();
        int j = 0;
        while (_flyingEnemies[j].getHp() != enemy.getHp())
        {
            j++;
            it++;
        }
        
        _flyingEnemies.erase(it);
        _world.DestroyBody(enemy.getBody());
    }
    for (auto& enemy : _terrestrialEnemies)
    {
        std::vector<TerrestrialEnemy>::iterator it = _terrestrialEnemies.begin();
        int j = 0;
        while (_terrestrialEnemies[j].getHp() != enemy.getHp())
        {
            j++;
            it++;
        }

        _terrestrialEnemies.erase(it);
        _world.DestroyBody(enemy.getBody());
    }

   //_gameOver = false;
     _upgradePhase = false;
     _playerHasLeveledUp = false;

   
}

void AGame::win()
{
    _settings.getGameWindow().setMouseCursorVisible(true);
    if (_mainTheme.getStatus() == 2)
    {
        _mainTheme.stop();
    }

    if (_winTheme.getStatus() != 2)
    {
        _winTheme.play();
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



    for (auto& enemy : _flyingEnemies)
    {
        std::vector<FlyingEnemy>::iterator it = _flyingEnemies.begin();
        int j = 0;
        while (_flyingEnemies[j].getHp() != enemy.getHp())
        {
            j++;
            it++;
        }

        _flyingEnemies.erase(it);
        _world.DestroyBody(enemy.getBody());
    }
    for (auto& enemy : _terrestrialEnemies)
    {
        std::vector<TerrestrialEnemy>::iterator it = _terrestrialEnemies.begin();
        int j = 0;
        while (_terrestrialEnemies[j].getHp() != enemy.getHp())
        {
            j++;
            it++;
        }

        _terrestrialEnemies.erase(it);
        _world.DestroyBody(enemy.getBody());
    }

    //_gameOver = false;
    _upgradePhase = false;
    _playerHasLeveledUp = false;
}

void AGame::restart()
{
    _settings.getGameWindow().setMouseCursorVisible(false);
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
    FlyingEnemy::reset();
    TerrestrialEnemy::reset();
    _minAlphaInRange = 5;
    _maxAlphaInRange = 50;
    _nbOfAbiliyPoints = 0;
    _nbAttackPoints = 0;
    _nbMaxHpPoints = 0;
    _nbSpeedPoints = 0;
    _wave = 0;
    _money = 0;
    _waveText.setString("WAVE " + std::to_string(_wave));
    std::cout << "jusque la tout va bien" << std::endl;

    float groundYpos = _settings.getBattleAreaBorders().getPosition().y + _settings.getHeightOfBattleAreaBorders();
    float groundXpos = _settings.getBattleAreaBorders().getPosition().x;
    float widthPlayer = _player.getTexture().getSize().x * _player.getSprite().getScale().x;
    float heightPlayer = _player.getTexture().getSize().y * _player.getSprite().getScale().y;
    _player.getBodyDef().position = b2Vec2(groundXpos / SCALE + widthPlayer / 2 / SCALE - _outlineThickness / SCALE, groundYpos / SCALE - heightPlayer / 2 / SCALE);
     b2Body* playerBody = _world.CreateBody(&_player.getBodyDef());
     _player.setBody(playerBody);
     _player.getBody()->CreateFixture(&_player.getFixtureDef());
     _player.getBody()->SetLinearDamping(2.f);
     _playerStorer.push_back(std::move(_player));// setup player

    std::cout << _terrestrialEnemies.size() << std::endl;
    std::cout << _flyingEnemies.size() << std::endl;
    
    
    
    spawnTerrestrialEnemy();
    spawnFlyingEnemy();
    
}

    

void AGame::run()
{
	while (_settings.getGameWindow().isOpen())
	{
        _clock.restart();

        sf::Event event;
		getInputs(event);
        update();
        render();

        _totalTimeElapsed += _clock.getElapsedTime().asMilliseconds();
        _timerLevelUp += _clock.getElapsedTime().asMilliseconds();
        _timerDash += _clock.getElapsedTime().asMilliseconds();
        _timerDictacticiel += _clock.getElapsedTime().asMilliseconds();
	}
}

void AGame::getInputs(sf::Event& event)
{
    float x = sf::Mouse::getPosition(_settings.getGameWindow()).x;
    float y = sf::Mouse::getPosition(_settings.getGameWindow()).y;
    //std::cout << x << std::endl;
    //std::cout << y << std::endl;
    while (_settings.getGameWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _settings.getGameWindow().close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Space)
            {
                for (auto& player : _playerStorer )
                {
                    float playerXpos = player.getBody()->GetPosition().x * SCALE;
                    float playerYpos = player.getBody()->GetPosition().y * SCALE;
                    float widthPlayer = player.getTexture().getSize().x * player.getSprite().getScale().x;
                    float heightPlayer = player.getTexture().getSize().y * player.getSprite().getScale().y;

                    sf::FloatRect boxCollider(playerXpos - widthPlayer / 2.f, playerYpos - heightPlayer / 2.f, widthPlayer, heightPlayer - _outlineThickness);

                    if (boxCollider.intersects(_ground.getGlobalBounds()))
                    {
                        player.setUpDirection(true);
                        //std::cout << "I can jump now" << std::endl;
                    }
                }
                
            }
            if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
            {
                for (auto& player : _playerStorer)
                {
                    player.setDownDirection(true);
                }
               
            }
            if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::Left)
            {
                for (auto& player : _playerStorer)
                {
                    player.setLeftDirection(true);
                }
               
            }
            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
            {
                for (auto& player : _playerStorer)
                {
                    player.setRightDirection(true);
                }
               
            }

            if (event.key.code == sf::Keyboard::M)
            {
                for (auto& player : _playerStorer)
                {
                    if (!player.LongRangeMode())
                    {
                        player.isAttacking(true);
                    }
                }
               
               
            }
            if (event.key.code == sf::Keyboard::A)
            {
                if (!_gameOver)
                {
                    if (_terrestrialEnemies.empty() && _flyingEnemies.empty())
                    {
                        _terrestrialSpawnEffectSound.play();
                        _flyingSpawnEffectSound.play();
                        _upgradePhase = false;
                        _wave++;
                        _minAlphaInRange += 5;
                        _maxAlphaInRange += 5;
                        _waveText.setString("WAVE " + std::to_string(_wave));
                        std::cout << "wave: " << _wave << std::endl << std::endl;
                        if (_maxAlphaInRange >= 254)
                        {
                            _maxAlphaInRange = 254;
                        }

                        if (_wave % 5 == 0 && _wave > 0 )
                        {
                           
                            spawnFlyingEnemy();
                            spawnTerrestrialEnemy();
                            TerrestrialEnemy::levelUp();
                            FlyingEnemy::levelUp();

                            for (auto& enemy : _flyingEnemies)
                            {

                                enemy.boost();
                                std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;
                            } //spawn wave

                            for (auto& enemy : _terrestrialEnemies)
                            {

                                enemy.boost();
                                std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;
                            } //spawn wave
                        }


                        else if (_wave >= 5 && _wave < 12)
                        {

                            spawnFlyingEnemy();
                            spawnTerrestrialEnemy();
                            std::cout << "les ennemies rigolent plus!" << std::endl;
                            for (auto& enemy : _flyingEnemies)
                            {

                                enemy.boost();
                                std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;
                            } //spawn wave

                            for (auto& enemy : _terrestrialEnemies)
                            {

                                enemy.boost();
                                std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;
                            } //spawn wave

                        } //spawn wave

                        else if (_wave >= 12 && _wave < 20)
                        {

                            spawnFlyingEnemy();
                            spawnTerrestrialEnemy();
                            std::cout << "les ennemies rigolent plus!" << std::endl;
                            for (auto& enemy : _flyingEnemies)
                            {

                                enemy.boost();
                                std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;
                            } //spawn wave

                            for (auto& enemy : _terrestrialEnemies)
                            {

                                enemy.boost();
                                std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;
                            } //spawn wave

                        } //spawn wave


                        else if (_wave >= 20 && _wave < 40)
                        {

                            spawnFlyingEnemy();
                            spawnTerrestrialEnemy();
                            std::cout << "les ennemies rigolent plus!" << std::endl;
                            for (auto& enemy : _flyingEnemies)
                            {

                                enemy.boost();
                                enemy.boost();
                                std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;
                            } //spawn wave

                            for (auto& enemy : _terrestrialEnemies)
                            {

                                enemy.boost();
                                enemy.boost();
                                std::cout << "boosted atk:" << enemy.getAtk() << std::endl;
                                std::cout << "boosted hps:" << enemy.getHp() << std::endl;
                                std::cout << "new speed:" << enemy.getSpeed() << std::endl << std::endl;
                            } //spawn wave

                        } //spawn wave

                        else
                        {
                            spawnTerrestrialEnemy();
                            spawnFlyingEnemy();
                        }
                    }
                }
               

            }
            if (event.key.code == sf::Keyboard::F)
            {
                for (auto& player: _playerStorer)
                {
                    if (_flyIsUnlocked)
                    {
                        float playerXpos = player.getBody()->GetPosition().x * SCALE;
                        float playerYpos = player.getBody()->GetPosition().y * SCALE;
                        float widthPlayer = player.getTexture().getSize().x * player.getSprite().getScale().x;
                        float heightPlayer = player.getTexture().getSize().y * player.getSprite().getScale().y;

                        sf::FloatRect boxCollider(playerXpos - widthPlayer / 2.f, playerYpos - heightPlayer / 2.f, widthPlayer, heightPlayer - _outlineThickness);


                        if (boxCollider.intersects(_ground.getGlobalBounds()))
                        {
                            player.setStrongJump(true);
                        }
                    }
                    
                }
               
                
               
            }

            if (event.key.code == sf::Keyboard::LShift || event.key.code == sf::Keyboard::RShift)
            {
                for (auto& player: _playerStorer)
                {
                  
                    player.isDashing(true);
                    _iDash = 0;                    
                }
   
            }



            

        }
        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
            {
                for (auto& player : _playerStorer)
                {
                    player.setDownDirection(false);
                }
                
            }

            if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::Left)
            {
                for (auto& player : _playerStorer)
                {
                    player.setLeftDirection(false);
                }

               
            }
            if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
            {
                for (auto& player : _playerStorer)
                {
                    player.setRightDirection(false);
                }
               
            }
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                float widthRestartButton = _textureOfRestartButton.getSize().x;
                float heightRestartButton = _textureOfRestartButton.getSize().y;
                sf::FloatRect restartButtonBox(_spriteOfRestartButton.getPosition().x - widthRestartButton /2, _spriteOfRestartButton.getPosition().y - heightRestartButton /2, widthRestartButton, heightRestartButton);
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
                            for (auto& player: _playerStorer)
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

                    float widthDashItemBox = _textureOfDashItem.getSize().x;
                    float heightDashItemBox = _textureOfDashItem.getSize().y;
                    float DashItemX = _spriteOfDashItem.getPosition().x;
                    float DashItemY = _spriteOfDashItem.getPosition().y;
                    sf::FloatRect dashItemBox(DashItemX - widthDashItemBox / 2, DashItemY - heightDashItemBox / 2, widthDashItemBox, heightDashItemBox);
                    if (dashItemBox.contains(x, y))
                    {
                        if (_money >= _priceDashItem && !_dashIsUnlocked)
                        {
                            for (auto& player : _playerStorer)
                            {
                                _money -= _priceDashItem;
                                _moneySpentEffectSound.play();
                                _dashIsUnlocked = true;
                            }
                        }

                    }


                    float widthFlyItemBox = _textureOfFlyItem.getSize().x;
                    float heightFlyItemBox = _textureOfFlyItem.getSize().y;
                    float FlyItemX = _spriteOfFlyItem.getPosition().x;
                    float FlyItemY = _spriteOfFlyItem.getPosition().y;
                    sf::FloatRect FlyItemBox(FlyItemX - widthFlyItemBox / 2, FlyItemY - heightFlyItemBox / 2, widthFlyItemBox, heightFlyItemBox);
                    if (FlyItemBox.contains(x, y))
                    {
                        if (_money >= _priceFlyItem && !_flyIsUnlocked)
                        {
                            for (auto& player : _playerStorer)
                            {
                                _money -= _priceFlyItem;
                                _moneySpentEffectSound.play();
                                _flyIsUnlocked = true;
                            }

                       
                        }
                    }

                    

                }
                for (auto& player : _playerStorer)
                {
                    if (player.LongRangeMode())
                    {

                        for (auto& enemy : _terrestrialEnemies)
                        {
                            if (enemy.getHitbox().contains(x, y))
                            {
                                _longRangeAttack.play();
                                _iArrow = 0;
                                _arrowHitTarget = true;
                                _spriteOfArrow.setPosition(x, y);
                                enemy.getDamage(player.getAtk() / 2.5);
                                player.setHp(player.getHp() + (0.05 * player.getMaxHp()));
                                if (player.getHp() >= player.getMaxHp())
                                {
                                    player.setHp(player.getMaxHp());
                                }
                                std::cout << "atk player in long range: " << player.getAtk() / 2.5 << std::endl;
                                if (enemy.getHp() <= 0)
                                {
                                    _terrestrialSpawnEffectSound.play();
                                    enemy.setRightDirection(false);
                                    enemy.setLeftDirection(false);
                                    std::vector<TerrestrialEnemy>::iterator it = _terrestrialEnemies.begin();
                                    int j = 0;
                                    while (_terrestrialEnemies[j].getHp() != enemy.getHp())
                                    {
                                        j++;
                                        it++;
                                    }

                                    player.setXpGain(enemy.getXpDrop());
                                    _xpGainEffectSound.play();
                                    std::cout << "player got" << enemy.getXpDrop() << "xp!" << std::endl;
                                    _money += enemy.getMoneyDrop();
                                    player.setHp(player.getHp() + 0.1 * player.getMaxHp());
                                    if (player.getHp() >= player.getMaxHp())
                                    {
                                        player.setHp(player.getMaxHp());
                                    }
                                    _world.DestroyBody(enemy.getBody());
                                    _terrestrialEnemies.erase(it);

                                }
                            }
                        }

                        for (auto& enemy : _flyingEnemies)
                        {
                            if (enemy.getHitbox().contains(x, y))
                            {
                                _longRangeAttack.play();
                                _iArrow = 0;
                                _arrowHitTarget = true;
                                _spriteOfArrow.setPosition(x, y);
                                enemy.getDamage(player.getAtk() * 1.5);
                                player.setHp(player.getHp() + (0.05 * player.getMaxHp()));
                                if (player.getHp() >= player.getMaxHp())
                                {
                                    player.setHp(player.getMaxHp());
                                }
                                if (enemy.getHp() <= 0)
                                {
                                    _flyingSpawnEffectSound.play();
                                    enemy.setRightDirection(false);
                                    enemy.setLeftDirection(false);
                                    enemy.setDownDirection(false);
                                    std::vector<FlyingEnemy>::iterator it = _flyingEnemies.begin();
                                    int j = 0;
                                    while (_flyingEnemies[j].getHp() != enemy.getHp())
                                    {
                                        j++;
                                        it++;
                                    }
                                    player.setHp(player.getHp() + 0.1 * player.getMaxHp());
                                    if (player.getHp() >= player.getMaxHp())
                                    {
                                        player.setHp(player.getMaxHp());
                                    }
                                    player.setXpGain(enemy.getXpDrop());
                                    _xpGainEffectSound.play();
                                    std::cout << "player got" << enemy.getXpDrop() << "xp!" << std::endl;
                                    _money += enemy.getMoneyDrop();
                                    _world.DestroyBody(enemy.getBody());
                                    _flyingEnemies.erase(it);

                                }
                                
                            }
                        }

                    }
                    else
                    {
                        player.isAttacking(true);
                        if (player.facingLeft())
                        {
                            player.getSprite().setTexture(_textureOfPlayerPunchLeft);
                        }

                        else if (player.facingRight())
                        {
                            player.getSprite().setTexture(_textureOfPlayerPunchRight);
                        }
                    }

                    if (_upgradePhase)
                    {
                        sf::FloatRect buttonIncreaseSpeedBox(_speedPointsText.getPosition().x, _speedPointsText.getPosition().y, 100, 100);
                        if (buttonIncreaseSpeedBox.contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            if (_nbOfAbiliyPoints > 0)
                            {
                                _nbSpeedPoints++;
                                _nbOfAbiliyPoints--;
                                std::cout << "base speed before upgrade: " << player.getBaseSpeed() << std::endl;
                                float newBaseSpeed = player.getBaseSpeed();
                                newBaseSpeed += 0.1;
                                player.setBaseSpeed(newBaseSpeed);
                                std::cout << "base speed after upgrade: " << player.getBaseSpeed() << std::endl;
                            }

                            else
                            {
                                std::cout << "looser" << std::endl;
                            }

                        }

                        sf::FloatRect buttonIncreaseAttackBox(_attackPointsText.getPosition().x, _attackPointsText.getPosition().y, 100, 100);
                        if (buttonIncreaseAttackBox.contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            if (_nbOfAbiliyPoints > 0)
                            {
                                _nbAttackPoints++;
                                _nbOfAbiliyPoints--;
                                player.setBaseAtk(player.getBaseAtk() + (0.30 * player.getBaseAtk() * 0.46));
                                std::cout << "player enter the attack force!" << std::endl;
                            }

                            else
                            {
                                std::cout << "looser" << std::endl;
                            }

                        }

                        sf::FloatRect buttonIncreaseMaxHpBox(_maxHpPointsText.getPosition().x, _maxHpPointsText.getPosition().y, 100, 100);
                        if (buttonIncreaseMaxHpBox.contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            if (_nbOfAbiliyPoints > 0)
                            {
                                _nbMaxHpPoints++;
                                _nbOfAbiliyPoints--;
                                player.setBaseMaxHp(player.getBaseMaxHp() + (0.35 * player.getBaseMaxHp() + (0.1 * player.getBaseMaxHp())) * 0.77);
                                std::cout << "player enter the attack force!" << std::endl;
                            }

                            else
                            {
                                std::cout << "looser" << std::endl;
                            }

                        }
                    }
                    
                }
               

            }
            else if (event.mouseButton.button == sf::Mouse::Right)
            {
                for (auto& player : _playerStorer)
                {
                    if (player.LongRangeMode())
                    {
                        std::cout << "disable long range" << std::endl;
                        std::cout << "player atk: " << player.getAtk();
                        player.isInLongRangeMode(false);

                    }

                    else
                    {
                        std::cout << "activate long range" << std::endl;
                        player.isInLongRangeMode(true);
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
                    if (player.facingRight())
                    {
                        player.getSprite().setTexture(player.getTexture());
                    }

                    else if (player.facingLeft())
                    {
                        player.getSprite().setTexture(_player.getTextureOfPlayerLeft());
                    }
                }
               
            }
        }
    }
}

void AGame::update()
{   
   
    _world.Step(1 / 60.f, 8, 3);
    _settings.getGameWindow().clear(sf::Color::White);
 
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
            std::cout << "woww" << std::endl;
            _spriteOfDictacticielLeftMovement.setPosition(battleAreaX + widthLeftIndicatorDictacticiel / 2 + 100, battleAreaY + heightLeftIndicatorDictacticiel / 2 + 30);
        }
        _spriteOfDictacticielLeftMovement.move(-0.8, 0);

     
        float widthRightIndicatorDictacticiel = _textureOfDictacticielRightMovement.getSize().x;
        float heightRightIndicatorDictacticiel = _textureOfDictacticielRightMovement.getSize().y;
        if (_spriteOfDictacticielLeftMovement.getPosition().x < battleAreaX + widthLeftIndicatorDictacticiel / 2 + 10)
        {
            std::cout << "woww" << std::endl;
            _spriteOfDictacticielRightMovement.setPosition(battleAreaX + widthRightIndicatorDictacticiel / 2 + 100, battleAreaY + heightRightIndicatorDictacticiel / 2 + 90);
        }
        _spriteOfDictacticielRightMovement.move(0.8, 0);


        float widthJumpIndicatorDictacticiel = _textureOfDictacticielJumpMovement.getSize().x;
        float heightJumpIndicatorDictacticiel = _textureOfDictacticielJumpMovement.getSize().y;
        if (_spriteOfDictacticielLeftMovement.getPosition().x < battleAreaX + widthLeftIndicatorDictacticiel / 2 + 10)
        {
            std::cout << "woww" << std::endl;
            _spriteOfDictacticielJumpMovement.setPosition(battleAreaX + widthJumpIndicatorDictacticiel / 6 + widthJumpIndicatorDictacticiel / 2, battleAreaY + heightJumpIndicatorDictacticiel / 2 + 218);
        }
        _spriteOfDictacticielJumpMovement.move(0, -0.8);

        
        float widthAttackIndicatorDictacticiel = _textureOfDictacticielAttackMovementRed.getSize().x;
        float heightAttackIndicatorDictacticiel = _textureOfDictacticielAttackMovementRed.getSize().y;
        _spriteOfDictacticielAttackMovement.setPosition(battleAreaX + widthAttackIndicatorDictacticiel / 2 + 600, battleAreaY + heightAttackIndicatorDictacticiel / 2 + 5);
        _spriteOfDictacticielAttackMovement.setTexture(_textureOfDictacticielAttackMovementWhite);
        if (_timerDictacticiel > 50.f)
        {
            
            _spriteOfDictacticielAttackMovement.setTexture(_textureOfDictacticielAttackMovementRed);
            _timerDictacticiel = 0;
        }

        float widthSwitchIndicatorDictacticiel = _textureOfDictacticielSwitchMovement.getSize().x;
        float heightSwitchIndicatorDictacticiel = _textureOfDictacticielSwitchMovement.getSize().y;
        _spriteOfDictacticielSwitchMovement.setPosition(battleAreaX + widthSwitchIndicatorDictacticiel / 2 + 600, battleAreaY + heightSwitchIndicatorDictacticiel + 100);
    }

    else if (_wave == 0 && _upgradePhase)
    {
        _spriteOfDictacticielLeftMovement.setPosition(-100, -100);
        _spriteOfDictacticielRightMovement.setPosition(-100, -100);
        _spriteOfDictacticielJumpMovement.setPosition(-100, -100);
        _spriteOfDictacticielAttackMovement.setPosition(-100, -100);
        _spriteOfDictacticielSwitchMovement.setPosition(-100, -100);

    
    }

    
    

    
   
    
    float widthMoney = _textureOfMoney.getSize().x;
    float heighMoney = _textureOfMoney.getSize().y;
    _spriteOfMoney.setPosition(_settings.getBattleAreaBorders().getPosition().x + widthMoney / 3, _settings.getBattleAreaBorders().getPosition().y - heighMoney / 2 - _ceiling.getSize().y / 2);
    _moneyText.setPosition(_spriteOfMoney.getPosition().x + widthMoney / 2, _spriteOfMoney.getPosition().y - _moneyText.getCharacterSize() / 1.7);
    _moneyText.setString(std::to_string((int)_money));

    float widthXp = _textureOfEmptyXpBar.getSize().x;
    float heightXp = _textureOfEmptyXpBar.getSize().y;
    _spriteOfEmptyXpBar.setPosition(_settings.getBattleAreaBorders().getPosition().x + _settings.getWidthOfBattleAreaBorders() / 3.1 - widthXp / 2, _settings.getBattleAreaBorders().getPosition().y - heightXp / 2 - _ceiling.getSize().y / 2);
    _spriteOfFullXp.setPosition(_spriteOfEmptyXpBar.getPosition().x, _spriteOfEmptyXpBar.getPosition().y);

    for (auto& enemy : _terrestrialEnemies)
    {
        for (auto& player : _playerStorer)
        {
            if (!enemy.getHitbox().intersects(player.getHitbox()))
            {

                enemy.isAttacking(false);

                if (enemy.getHp() > 0)
                {

                    if (enemy.getSprite().getPosition().x > player.getSprite().getPosition().x)
                    {
                        //std::cout << "enemy a droite du joueur" << std::endl;
                        enemy.setLeftDirection(true);
                        enemy.setRightDirection(false);
                    }
                    else if (enemy.getSprite().getPosition().x < player.getSprite().getPosition().x)
                    {
                        //std::cout << "enemy a gauche du joueur" << std::endl;
                        enemy.setRightDirection(true);
                        enemy.setLeftDirection(false);

                    }
                }

            }
            else if (enemy.getHitbox().intersects(player.getHitbox()))
            {
                enemy.setLeftDirection(false);
                enemy.setRightDirection(false);
                enemy.isAttacking(true);
            }
            if (_totalTimeElapsed >= 300.f && enemy.getHitboxOfAtk().intersects(player.getHitbox()))
            {
                player.getDamage(enemy.getAtk());
                std::cout << " aie" << std::endl;
                _totalTimeElapsed = 0;
            }

        }

        enemy.update();
    }//terrestrial enemies behavior
    for (auto& enemy : _flyingEnemies)
    {

        for (auto& player : _playerStorer)
        {
            if (!enemy.getHitbox().intersects(player.getHitbox()))
            {

                enemy.isAttacking(false);
                if (enemy.getHp() > 0)
                {
                    if (!enemy.daashing())
                    {

                        if (enemy.getSprite().getPosition().x > player.getSprite().getPosition().x)
                        {
                            // std::cout << "enemy a droite du joueur" << std::endl;
                            enemy.setLeftDirection(true);
                            enemy.setRightDirection(false);
                        }
                        else if (enemy.getSprite().getPosition().x < player.getSprite().getPosition().x)
                        {
                            //std::cout << "enemy a gauche du joueur" << std::endl;
                            enemy.setRightDirection(true);
                            enemy.setLeftDirection(false);
                        }

                    }


                    if (enemy.getHitboxOfDash().contains(player.getSprite().getPosition().x, player.getSprite().getPosition().y))
                    {
                        //std::cout << "pas gaiche pas gauche" << std::endl;
                        enemy.isDaashing(true);
                        enemy.setLeftDirection(false);
                        enemy.setRightDirection(false);
                        enemy.setUpDirection(false);
                    }

                    if (enemy.daashing())
                    {
                        if (enemy.getSprite().getPosition().y <= enemy.getHitboxOfDash().top + enemy.getHitboxOfDash().height)
                        {
                            enemy.setDownDirection(true);
                        }

                        if (enemy.getHitbox().top + enemy.getHitbox().height >= player.getHitbox().top)
                        {
                            enemy.isDaashing(false);
                            enemy.setUpDirection(true);
                            enemy.setDownDirection(false);
                        }
                    }



                }
            }
            else if (enemy.getHitbox().intersects(player.getHitbox()))
            {
                enemy.setLeftDirection(false);
                enemy.setRightDirection(false);
                enemy.setUpDirection(true);
                enemy.setDownDirection(false);
                enemy.isAttacking(true);
                enemy.isDaashing(false);
            }
            if (_totalTimeElapsed >= 300.f && enemy.getHitboxOfAtk().intersects(player.getHitbox()))
            {
                player.getDamage(enemy.getAtk());
                _totalTimeElapsed = 0;
            }
        }
        enemy.update();
    }//flying enemies behavior

   
    
    if (_wave >= 0)
    {
        if (_flyingEnemies.empty() && _terrestrialEnemies.empty())
        {
            _upgradePhase = true;
        }

        else if(!_flyingEnemies.empty() && !_terrestrialEnemies.empty())
        {
            _settings.getGameWindow().setMouseCursorVisible(false);
        }
    }
   

    for (auto& player : _playerStorer)
    {
        player.update();
    }

    for (auto& player : _playerStorer)
    {
        if (player.attacking())
        {

            _shortRangeAttack.play();
            for (auto& enemy : _terrestrialEnemies)
            {

                if (player.getHitboxOfAtk().intersects(enemy.getHitbox()))
                {
                    enemy.getDamage(player.getAtk() * 1.4);
                    player.setHp(player.getHp() + (0.05 * player.getMaxHp()));
                    if (player.getHp() >= player.getMaxHp())
                    {
                        player.setHp(player.getMaxHp());
                    }
                    std::cout << "atk player in short range" << player.getAtk() << std::endl;
                    // std::cout << enemy.getHp() << std::endl;
                    if (enemy.getHp() <= 0)
                    {
                        _terrestrialSpawnEffectSound.play();
                        enemy.setRightDirection(false);
                        enemy.setLeftDirection(false);
                        std::vector<TerrestrialEnemy>::iterator it = _terrestrialEnemies.begin();
                        int j = 0;
                        while (_terrestrialEnemies[j].getHp() != enemy.getHp())
                        {
                            j++;
                            it++;
                        }
                        player.setHp(player.getHp() + 0.1 * player.getMaxHp());
                        if (player.getHp() >= player.getMaxHp())
                        {
                            player.setHp(player.getMaxHp());
                        }
                        player.setXpGain(enemy.getXpDrop());
                        _xpGainEffectSound.play();
                        std::cout << "player got" << enemy.getXpDrop() << "xp!" << std::endl;
                        _money += enemy.getMoneyDrop();
                        _world.DestroyBody(enemy.getBody());
                        _terrestrialEnemies.erase(it);
                    }
                }

                player.isAttacking(false);
            }
            for (auto& enemy : _flyingEnemies)
            {

                if (player.getHitboxOfAtk().intersects(enemy.getHitbox()))
                {
                    player.setHp(player.getHp() + (0.05 * player.getMaxHp()));
                    enemy.getDamage(player.getAtk() * 0.8);
                    //std::cout << enemy.getHp() << std::endl;
                    if (enemy.getHp() <= 0)
                    {
                        _flyingSpawnEffectSound.play();
                        enemy.setRightDirection(false);
                        enemy.setLeftDirection(false);
                        enemy.setDownDirection(false);
                        std::vector<FlyingEnemy>::iterator it = _flyingEnemies.begin();
                        int j = 0;
                        while (_flyingEnemies[j].getHp() != enemy.getHp())
                        {
                            j++;
                            it++;
                        }
                        player.setHp(player.getHp() + 0.1 * player.getMaxHp());
                        if (player.getHp() >= player.getMaxHp())
                        {
                            player.setHp(player.getMaxHp());
                        }
                        player.setXpGain(enemy.getXpDrop());
                        _xpGainEffectSound.play();
                        std::cout << "player got" << enemy.getXpDrop() << "xp!" << std::endl;
                        _money += enemy.getMoneyDrop();
                        _world.DestroyBody(enemy.getBody());
                        _flyingEnemies.erase(it);


                    }
                }

                player.isAttacking(false);
            }
            player.isAttacking(false);
        }
    }

    for (auto& player : _playerStorer)
    {
        if (player.LongRangeMode())
        {
            _cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(_settings.getGameWindow())));
            if (player.facingRight())
            {
                player.getSprite().setTexture(_textureOfPlayerBowRight);
            }

            else
            {
                player.getSprite().setTexture(_textureOfPlayerBowLeft);
            }
        }

        else
        {
            _cursorSprite.setPosition(-1000, -1000);
        }
    }

    for (auto& player : _playerStorer)
    {
        if (_dashIsUnlocked)
        {
            if (player.dashing())
            {
                _dashEffectSound.play();
                _iDash++;
                float force = _player.getBody()->GetMass() * 9.8f;
                if (_iDash < 3)
                {
                    std::cout << "yes" << std::endl;

                    if (player.facingRight())
                    {
                        player.getBody()->ApplyForce(b2Vec2(force * 120, 0), b2Vec2(player.getBody()->GetWorldCenter().x, player.getBody()->GetWorldCenter().y), true);
                    }

                    else if (player.facingLeft())
                    {
                        player.getBody()->ApplyForce(b2Vec2(-force * 120, 0), b2Vec2(player.getBody()->GetWorldCenter().x, player.getBody()->GetWorldCenter().y), true);
                    }
                }

                if (_iDash > 10)
                {
                    player.isDashing(false);
                }




                for (auto& enemy : _terrestrialEnemies)
                {
                    if (player.getHitbox().intersects(enemy.getHitbox()))
                    {
                        if (player.facingRight())
                        {
                            enemy.getBody()->ApplyForce(b2Vec2(force * 2, 0), b2Vec2(enemy.getBody()->GetWorldCenter().x, enemy.getBody()->GetWorldCenter().y), true);
                        }

                        else if (player.facingLeft())
                        {
                            enemy.getBody()->ApplyForce(b2Vec2(-force * 2, 0), b2Vec2(enemy.getBody()->GetWorldCenter().x, enemy.getBody()->GetWorldCenter().y), true);
                        }

                                    
                        enemy.getDamage(player.getAtk() * 1.5);
                        player.setHp(player.getHp() + (0.2 * player.getMaxHp()));
                        if (player.getHp() >= player.getMaxHp())
                        {
                            player.setHp(player.getMaxHp());
                        }
                        if (enemy.getHp() <= 0)
                        {
                            _terrestrialSpawnEffectSound.play();
                            enemy.setRightDirection(false);
                            enemy.setLeftDirection(false);
                            std::vector<TerrestrialEnemy>::iterator it = _terrestrialEnemies.begin();
                            int j = 0;
                            while (_terrestrialEnemies[j].getHp() != enemy.getHp())
                            {
                                j++;
                                it++;
                            }

                            player.setXpGain(enemy.getXpDrop());
                            _xpGainEffectSound.play();
                            std::cout << "player got" << enemy.getXpDrop() << "xp!" << std::endl;
                            _money += enemy.getMoneyDrop();
                            player.setHp(player.getHp() + 0.1 * player.getMaxHp());
                            if (player.getHp() >= player.getMaxHp())
                            {
                                player.setHp(player.getMaxHp());
                            }
                            _world.DestroyBody(enemy.getBody());
                            _terrestrialEnemies.erase(it);

                        }
                        player.isDashing(false);
                    }
                }

                for (auto& enemy : _flyingEnemies)
                {

                    if (player.getHitbox().intersects(enemy.getHitbox()))
                    {
                        if (player.facingRight())
                        {
                            enemy.getBody()->ApplyForce(b2Vec2(force * 2, 0), b2Vec2(enemy.getBody()->GetWorldCenter().x, enemy.getBody()->GetWorldCenter().y), true);
                        }

                        else if (player.facingLeft())
                        {
                            enemy.getBody()->ApplyForce(b2Vec2(-force * 2, 0), b2Vec2(enemy.getBody()->GetWorldCenter().x, enemy.getBody()->GetWorldCenter().y), true);
                        }


                        enemy.getDamage(player.getAtk() * 1.5);
                        player.setHp(player.getHp() + (0.2 * player.getMaxHp()));
                        if (player.getHp() >= player.getMaxHp())
                        {
                            player.setHp(player.getMaxHp());
                        }
                        if (enemy.getHp() <= 0)
                        {
                            _flyingSpawnEffectSound.play();
                            enemy.setRightDirection(false);
                            enemy.setLeftDirection(false);
                            enemy.setDownDirection(false);
                            std::vector<FlyingEnemy>::iterator it = _flyingEnemies.begin();
                            int j = 0;
                            while (_flyingEnemies[j].getHp() != enemy.getHp())
                            {
                                j++;
                                it++;
                            }
                            player.setHp(player.getHp() + 0.1 * player.getMaxHp());
                            if (player.getHp() >= player.getMaxHp())
                            {
                                player.setHp(player.getMaxHp());
                            }
                            player.setXpGain(enemy.getXpDrop());
                            std::cout << "player got" << enemy.getXpDrop() << "xp!" << std::endl;
                            _money += enemy.getMoneyDrop();
                            _world.DestroyBody(enemy.getBody());
                            _flyingEnemies.erase(it);

                        }

                        player.isDashing(false);
                    }
                }


            }
        }



    }

    for (auto& player : _playerStorer)
    {
        if (player.getHp() <= 0 && !_gameOver)
        {
            _playerStorer.erase(_playerStorer.begin());
            _world.DestroyBody(player.getBody());
            _gameOver = true;
        }
    }

   
   



    if (_arrowHitTarget)
    {
        _iArrow++;
        if (_iArrow > 10)
        {
            _spriteOfArrow.setPosition(-100, -100);
            _arrowHitTarget = false;
            
        }
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


    if (_upgradePhase)
    {
        _settings.getGameWindow().setMouseCursorVisible(true);

        for (auto& player : _playerStorer)
        {
            if ((_wave + 1) % 40 == 0)
            {
                _playerStorer.erase(_playerStorer.begin());
                _world.DestroyBody(player.getBody());
                _win = true;
            }
        }

        if (!_restore)
        {
            if ((_wave + 1) % 5 == 0)
            {
                _restore = true;

            }

            if (_restore)
            {
                _restoreCounter++;
                if (_restoreCounter == 1)
                {
                    // std::cout << std::endl<< std::endl << std::endl << "max hp player" << _player.getMaxHp() << std::endl;
                }

            }
        }

        else
        {
            _restore = false;
        }

        // std::cout << "ability points remaining: " << _nbOfAbiliyPoints << std::endl;


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
            std::cout << "woww" << std::endl;
            _spriteOfStore.setPosition((widthBattleArea * 0.95), (0.20 * heighBattleArea) + heightStoreText);
        }

        float widthHealItem = _textureOfHealItem.getSize().x;
        float heightHealItem = _textureOfHealItem.getSize().y;
        _spriteOfHealItem.setPosition(storeX, storeY + heightHealItem);
        float healItemX = _spriteOfHealItem.getPosition().x;
        float healItemY = _spriteOfHealItem.getPosition().y;
        _spriteOfBoxPriceHealItem.setPosition(healItemX, healItemY + 38); //heal item price box
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


        float widthDashItem = _textureOfDashItem.getSize().x;
        float heightDashItem = _textureOfDashItem.getSize().y;
        _spriteOfDashItem.setPosition(storeX, storeY + 240);
        float dashItemX = _spriteOfDashItem.getPosition().x;
        float dashItemY = _spriteOfDashItem.getPosition().y;
        _spriteOfBoxPriceDashItem.setPosition(dashItemX, dashItemY + 42); //dash item price box

        if (_money >= _priceDashItem && !_dashIsUnlocked)
        {
            _spriteOfBoxPriceDashItem.setColor(sf::Color(255, 255, 128));
        }

        else
        {
            _spriteOfBoxPriceDashItem.setColor(sf::Color(184, 184, 184));
        }

        float boxPriceDashItemX = _spriteOfBoxPriceDashItem.getPosition().x;
        float boxPriceDashItemY = _spriteOfBoxPriceDashItem.getPosition().y;
        float widthBoxPriceDashItem = _textureOfPriceBoxForItems.getSize().x;
        float heightBoxPriceDashItem = _textureOfPriceBoxForItems.getSize().y;
        _dashItemPrice.setPosition(boxPriceDashItemX - _dashItemPrice.getCharacterSize() / 2, boxPriceDashItemY - 20);
        _dashItemPrice.setString(std::to_string(int(_priceDashItem))); //dash item price text

        float DashItemPriceX = _dashItemPrice.getPosition().x;
        float DashItemPriceY = _dashItemPrice.getPosition().y;
        float widthDashItemPriceDecoration = _textureOfMoney.getSize().x * _spriteOfDashItemPriceDecoration.getScale().x;
        float heightDashItemPriceDecoration = _textureOfMoney.getSize().y * _spriteOfDashItemPriceDecoration.getScale().y;
        _spriteOfDashItemPriceDecoration.setPosition(DashItemPriceX - widthDashItemPriceDecoration, DashItemPriceY + heightDashItemPriceDecoration / 2 - 5); //dash item decoration 

        float widthFlyItem = _textureOfFlyItem.getSize().x;
        float heightFlyItem = _textureOfFlyItem.getSize().y;
        _spriteOfFlyItem.setPosition(storeX, storeY + 380);
        float FlyItemX = _spriteOfFlyItem.getPosition().x;
        float FlyItemY = _spriteOfFlyItem.getPosition().y;
        _spriteOfBoxPriceFlyItem.setPosition(FlyItemX, FlyItemY + 42); //fly item price box

        if (_money >= _priceFlyItem && !_flyIsUnlocked)
        {
            _spriteOfBoxPriceFlyItem.setColor(sf::Color(255, 255, 128));
        }

        else
        {
            _spriteOfBoxPriceFlyItem.setColor(sf::Color(184, 184, 184));
        }

        float boxPriceFlyItemX = _spriteOfBoxPriceFlyItem.getPosition().x;
        float boxPriceFlyItemY = _spriteOfBoxPriceFlyItem.getPosition().y;
        float widthBoxPriceFlyItem = _textureOfPriceBoxForItems.getSize().x;
        float heightBoxPriceFlyItem = _textureOfPriceBoxForItems.getSize().y;
        _FlyItemPrice.setPosition(boxPriceFlyItemX - _FlyItemPrice.getCharacterSize() / 2, boxPriceFlyItemY - 20);
        _FlyItemPrice.setString(std::to_string(int(_priceFlyItem))); //fly item price text

        float FlyItemPriceX = _FlyItemPrice.getPosition().x;
        float FlyItemPriceY = _FlyItemPrice.getPosition().y;
        float widthFlyItemPriceDecoration = _textureOfMoney.getSize().x * _spriteOfFlyItemPriceDecoration.getScale().x;
        float heightFlyItemPriceDecoration = _textureOfMoney.getSize().y * _spriteOfFlyItemPriceDecoration.getScale().y;
        _spriteOfFlyItemPriceDecoration.setPosition(FlyItemPriceX - widthFlyItemPriceDecoration, FlyItemPriceY + heightFlyItemPriceDecoration / 2 - 5); //fly item decoration 





        _spriteOfIncreaseSpeed.setPosition(battleAreaX + widthBattleArea / 5, battleAreaY + heighBattleArea / 4);
        _speedPointsText.setPosition(_spriteOfIncreaseSpeed.getPosition().x + 10, _spriteOfIncreaseSpeed.getPosition().y + 13);
        _speedPointsText.setString(std::to_string(_nbSpeedPoints));

        _spriteOfIncreaseAttack.setPosition(battleAreaX + widthBattleArea / 2.7, battleAreaY + heighBattleArea / 4);
        _attackPointsText.setPosition(_spriteOfIncreaseAttack.getPosition().x - 13, _spriteOfIncreaseAttack.getPosition().y + 18);
        _attackPointsText.setString(std::to_string(_nbAttackPoints));

        _spriteOfIncreaseMaxHp.setPosition(battleAreaX + widthBattleArea / 1.8, battleAreaY + heighBattleArea / 4);
        _maxHpPointsText.setPosition(_spriteOfIncreaseMaxHp.getPosition().x - 9, _spriteOfIncreaseMaxHp.getPosition().y + 42);
        _maxHpPointsText.setString(std::to_string(_nbMaxHpPoints));



        if (_totalTimeElapsed >= 200.f)
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

            _spriteOfIncreaseAttack.move(0, 10);
            _attackPointsText.move(0, 10);

            _spriteOfIncreaseMaxHp.move(0, 10);
            _maxHpPointsText.move(0, 10);

            _totalTimeElapsed = 0;
        }

    }



    updateTheXp();

    if (_playerHasLeveledUp)
    {
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


        if (_timerLevelUp < 2000 && _iLevelUp < 200)
        {
            _iLevelUp++;
            for (auto& player : _playerStorer)
            {
                if (player.facingRight() && !player.attacking())
                {
                    _spriteOfLevelUp.setTexture(_textureOfLevelUp);
                }
                else if (player.facingLeft() && !player.attacking())
                {
                    _spriteOfLevelUp.setTexture(_textureOfLevelUp4);
                }
                else if (player.facingRight() && player.attacking())
                {
                    _spriteOfLevelUp.setTexture(_textureOfLevelUpAttackRight);
                }
                else if (player.facingLeft() && player.attacking())
                {
                    _spriteOfLevelUp.setTexture(_textureOfLevelUpAttackLeft);
                }

                _spriteOfLevelUp.setPosition(playerX, playerY);
                _textForLevelUp.setPosition(playerX - _textForLevelUp.getCharacterSize() - 40, playerY - heightPlayer / 2 - 50);
                player.getLevelIndicator().setColor(sf::Color(214, 244, 68));
            }

            //_player.getLevelIndicator().setOutlineColor(sf::Color(214, 244, 68));
            if (_timerLevelUp > 10)
            {
                _spriteOfLevelUp.move(0, 10);
                _textForLevelUp.move(0, 10);
                _timerLevelUp = 0;
            }
        }

        else
        {
            _spriteOfLevelUp.setPosition(-100, -100);
            _textForLevelUp.setPosition(-100, -100);
            for (auto& player : _playerStorer)
            {
                player.getLevelIndicator().setFillColor(sf::Color::Black);
                player.getLevelIndicator().setOutlineColor(sf::Color::Black);
            }


        }

    }

    else
    {
        _spriteOfLevelUp.setPosition(-100, -100);
        _textForLevelUp.setPosition(-100, -100);
        for (auto& player : _playerStorer)
        {
            player.getLevelIndicator().setFillColor(sf::Color::Black);
            player.getLevelIndicator().setOutlineColor(sf::Color::Black);
        }
    }

    if (_nbOfAbiliyPoints <= 0 && !_upgradePhase)
    {
        _playerHasLeveledUp = false;
    }



    
   
    
 
   
}

void AGame::render()
{
    
    _settings.getGameWindow().draw(_settings.getGameWindowBorders());
    _settings.getGameWindow().draw(_settings.getBattleAreaBorders());
    _settings.getGameWindow().draw(_ground);
    if (_wave == 0)
    {
        _settings.getGameWindow().draw(_spriteOfDictacticielLeftMovement);
        _settings.getGameWindow().draw(_spriteOfDictacticielRightMovement);
        _settings.getGameWindow().draw(_spriteOfDictacticielJumpMovement);
        _settings.getGameWindow().draw(_spriteOfDictacticielAttackMovement);
        _settings.getGameWindow().draw(_spriteOfDictacticielSwitchMovement);
    }

    for (auto& enemy : _terrestrialEnemies)
    {
        enemy.draw(_settings.getGameWindow());
    }
    for (auto& enemy : _flyingEnemies)
    {
        enemy.draw(_settings.getGameWindow());
    }

    _settings.getGameWindow().draw(_spriteOfMoney);
    _settings.getGameWindow().draw(_moneyText);
    _settings.getGameWindow().draw(_waveText);
    _settings.getGameWindow().draw(_spriteOfEmptyXpBar);
    _settings.getGameWindow().draw(_spriteOfFullXp);

    if (_upgradePhase  && _playerHasLeveledUp)
    {
        _settings.getGameWindow().draw(_spriteOfIncreaseSpeed);
        _settings.getGameWindow().draw(_speedPointsText);

        _settings.getGameWindow().draw(_spriteOfIncreaseAttack);
        _settings.getGameWindow().draw(_attackPointsText);

        _settings.getGameWindow().draw(_spriteOfIncreaseMaxHp);
        _settings.getGameWindow().draw(_maxHpPointsText);

    }

    if (_upgradePhase)
    {
        _settings.getGameWindow().draw(_spriteOfStore);

        _settings.getGameWindow().draw(_spriteOfHealItem);
        _settings.getGameWindow().draw(_spriteOfBoxPriceHealItem);
        _settings.getGameWindow().draw(_healItemPrice);
        _settings.getGameWindow().draw(_spriteOfHealItemPriceDecoration);


        _settings.getGameWindow().draw(_spriteOfDashItem);
        _settings.getGameWindow().draw(_spriteOfBoxPriceDashItem);
        _settings.getGameWindow().draw(_dashItemPrice);
        _settings.getGameWindow().draw(_spriteOfDashItemPriceDecoration);

        _settings.getGameWindow().draw(_spriteOfFlyItem);
        _settings.getGameWindow().draw(_spriteOfBoxPriceFlyItem);
        _settings.getGameWindow().draw(_FlyItemPrice);
        _settings.getGameWindow().draw(_spriteOfFlyItemPriceDecoration);

        _settings.getGameWindow().draw(_textNextWave);
    }

  
    
    _settings.getGameWindow().draw(_spriteOfArrow);

   
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
    _settings.getGameWindow().draw(_spriteOfRestartButton);

  


    
   

    _settings.getGameWindow().draw(_cursorSprite);
    _settings.getGameWindow().display();
}


