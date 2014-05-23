CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )

# Project
PROJECT( qxneur )

# Common CMake modules
SET( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/CMake )
INCLUDE( common )

# Qt
FIND_PACKAGE( Qt4 4.6.0 REQUIRED )
INCLUDE( ${QT_USE_FILE} )

# Directories
INCLUDE_DIRECTORIES( . src src/Config ${CMAKE_CURRENT_BINARY_DIR} )


SET( QXNEUR_SRC
  src/main.cpp
  src/QXNeur.cpp
  src/QXNLanguage.cpp
  src/QXNKeyboard.cpp
  src/QXNMenu.cpp
  src/QXNTrayIcon.cpp
  src/PropertyMapper.cpp
  src/Config/QXNConfig.cpp
  src/Config/QXNConfigDialog.cpp
  src/Config/QXNApplicationSettingsDialog.cpp
  src/Config/QXNAbbreviationEditDialog.cpp
  src/Config/QXNApplicationsModel.cpp
)

SET( QXNEUR_MOC_SRC
  src/QXNeur.h
  src/QXNLanguage.h
  src/QXNKeyboard.h
  src/QXNMenu.h
  src/QXNTrayIcon.h
  src/Config/QXNConfig.h
  src/Config/QXNConfigDialog.h
  src/Config/QXNApplicationSettingsDialog.h
  src/Config/QXNAbbreviationEditDialog.h
  src/Config/QXNApplicationsModel.h
)

SET( QXNEUR_UI_SRC
  src/Config/QXNConfigDialog.ui
  src/Config/QXNApplicationSettingsDialog.ui
  src/Config/QXNAbbreviationEditDialog.ui
)

SET( QXNEUR_RCC_SRC
  images/images.qrc
)

SET( QXNEUR_TS
  translations/qxneur_ru.ts
)

SET(BIN_TARGET qxneur)

# Updating and generating the translation
#QT4_CREATE_TRANSLATION(qm_files ${CMAKE_CURRENT_SOURCE_DIR}/src ${translations} OPTIONS -no-ui-lines -locations relative -source-language english)
#ADD_CUSTOM_TARGET(${tr_target} DEPENDS ${qm_files})

# Pre-processing by MOC, UIC and QRC
QT4_WRAP_CPP( QXNEUR_MOC ${QXNEUR_MOC_SRC} )
QT4_WRAP_CPP( QXNEUR_MOC src/PropertyMapper.h OPTIONS -fsrc/PropertyMapperPrivate.h )
QT4_WRAP_UI( QXNEUR_UI ${QXNEUR_UI_SRC} )
QT4_ADD_RESOURCES( QXNEUR_RCC ${QXNEUR_RCC_SRC} )
QT4_ADD_TRANSLATION( QXNEUR_QM ${QXNEUR_TS} )

SET( TRANSLATIONS_DIR "${CMAKE_INSTALL_PREFIX}/share/qxneur/translations" )
add_definitions( -DTRANSLATIONS_DIR=\"${TRANSLATIONS_DIR}\" )

# Building the executable
ADD_EXECUTABLE( ${BIN_TARGET}
    ${QXNEUR_SRC}
    ${QXNEUR_MOC}
    ${QXNEUR_UI}
    ${QXNEUR_RCC}
    ${QXNEUR_QM}
)

TARGET_LINK_LIBRARIES(${BIN_TARGET}
    ${QT_LIBRARIES}
    xnconfig
    Xmu
    X11
    xneur
)
