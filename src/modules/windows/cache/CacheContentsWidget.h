/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2013 - 2017 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
**************************************************************************/

#ifndef OTTER_CacheContentsWidget_H
#define OTTER_CacheContentsWidget_H

#include "../../../ui/ContentsWidget.h"

#include <QtGui/QStandardItemModel>

namespace Otter
{

namespace Ui
{
	class CacheContentsWidget;
}

class Window;

class CacheContentsWidget : public ContentsWidget
{
	Q_OBJECT

public:
	explicit CacheContentsWidget(const QVariantMap &parameters, Window *window);
	~CacheContentsWidget();

	void print(QPrinter *printer) override;
	Action* getAction(int identifier) override;
	QString getTitle() const override;
	QLatin1String getType() const override;
	QUrl getUrl() const override;
	QIcon getIcon() const override;
	WebWidget::LoadingState getLoadingState() const override;
	bool eventFilter(QObject *object, QEvent *event) override;

public slots:
	void triggerAction(int identifier, const QVariantMap &parameters = QVariantMap()) override;

protected:
	void changeEvent(QEvent *event) override;
	QStandardItem* findDomain(const QString &domain);
	QStandardItem* findEntry(const QUrl &entry);
	QUrl getEntry(const QModelIndex &index) const;

protected slots:
	void populateCache();
	void addEntry(const QUrl &entry);
	void removeEntry(const QUrl &entry);
	void removeEntry();
	void removeDomainEntries();
	void removeDomainEntriesOrEntry();
	void openEntry(const QModelIndex &index = QModelIndex());
	void copyEntryLink();
	void showContextMenu(const QPoint &position);
	void updateActions();

private:
	QStandardItemModel *m_model;
	QHash<int, Action*> m_actions;
	bool m_isLoading;
	Ui::CacheContentsWidget *m_ui;
};

}

#endif
