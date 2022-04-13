/* === This file is part of Calamares - <https://calamares.io> ===
 *
 *   SPDX-FileCopyrightText: 2014-2015 Teo Mrnjavac <teo@kde.org>
 *   SPDX-FileCopyrightText: 2019-2020 Adriaan de Groot <groot@kde.org>
 *   SPDX-License-Identifier: GPL-3.0-or-later
 *
 *   Calamares is Free Software: see the License-Identifier above.
 *
 */

#ifndef CHECKER_RESULTSLISTWIDGET_H
#define CHECKER_RESULTSLISTWIDGET_H

#include "ResultWidget.h"

#include "Config.h"

#include <QWidget>

class QBoxLayout;
class QLabel;
class ResultsListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ResultsListWidget( Config* config, QWidget* parent );

private:
    /// @brief A link in the explanatory text has been clicked
    void linkClicked( const QString& link );
    /// @brief The model of requirements changed
    void requirementsChanged();

    void retranslate();

    QList< ResultWidget* > m_resultWidgets;  ///< One widget for each unsatisfied entry
    Config* m_config = nullptr;

    // UI parts, which need updating when the model changes
    QLabel* m_explanation = nullptr;
    QBoxLayout* m_mainLayout = nullptr;
    QBoxLayout* m_entriesLayout = nullptr;
    // We count how many requirements we have seen; since the model
    // does not shrink, we can avoid reacting to model-is-cleared
    // events because the size of the model is then (briefly) smaller
    // than what we expect.
    int m_requirementsSeen = 0;
};

#endif  // CHECKER_RESULTSLISTWIDGET_H
