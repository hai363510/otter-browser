/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2015 Jan Bajer aka bajasoft <jbajer@gmail.com>
* Copyright (C) 2015 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
**************************************************************************/

#ifndef OTTER_UPDATECHECKER_H
#define OTTER_UPDATECHECKER_H

#include "SessionsManager.h"

#include <QtNetwork/QNetworkReply>

namespace Otter
{

struct UpdateInformation
{
	QString channel;
	QString version;
	QUrl detailsUrl;
};

class UpdateChecker : public QObject
{
	Q_OBJECT

public:
	explicit UpdateChecker(QObject *parent = NULL, bool inBackground = true);

protected slots:
	void runUpdateCheck();
	void runUpdate();

private:
	QNetworkReply *m_networkReply;
	QString m_detailsUrl;
	bool m_isInBackground;

signals:
	void finished(const QList<UpdateInformation> &availableUpdates);
};

}

#endif