/*
 * Strawberry Music Player
 * This file was part of Clementine.
 * Copyright 2010, David Sansome <me@davidsansome.com>
 *
 * Strawberry is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Strawberry is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Strawberry.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef GLOBALSHORTCUTBACKEND_GSD_H
#define GLOBALSHORTCUTBACKEND_GSD_H

#include "config.h"

#include <stdbool.h>

#include <QObject>
#include <QtGlobal>
#include <QPair>
#include <QVector>
#include <QHash>
#include <QString>
#include <QDBusPendingCallWatcher>

#include "globalshortcutbackend.h"

class GlobalShortcuts;
class OrgGnomeSettingsDaemonMediaKeysInterface;

class GlobalShortcutBackendGSD : public GlobalShortcutBackend {
  Q_OBJECT

 public:
  explicit GlobalShortcutBackendGSD(GlobalShortcuts *parent);
  ~GlobalShortcutBackendGSD();

  static const char *kGsdService;
  static const char *kGsdService2;
  static const char *kGsdPath;

 protected:
  bool RegisterInNewThread() const { return true; }
  bool DoRegister();
  void DoUnregister();

 private slots:
  void RegisterFinished(QDBusPendingCallWatcher *watcher);

  void GnomeMediaKeyPressed(const QString &application, const QString &key);

 private:
  OrgGnomeSettingsDaemonMediaKeysInterface *interface_;
  bool is_connected_;

};

#endif  // GLOBALSHORTCUTBACKEND_GSD_H
