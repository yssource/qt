/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef Patternist_XsdAnnotation_H
#define Patternist_XsdAnnotation_H

#include "qderivedstring_p.h"
#include "qxsdapplicationinformation_p.h"
#include "qxsddocumentation_p.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @short Represents a XSD annotation object.
     *
     * This class represents the <em>annotation</em> object of a XML schema as described
     * <a href="http://www.w3.org/TR/xmlschema11-1/#cAnnotations">here</a>.
     *
     * @ingroup Patternist_schema
     * @author Tobias Koenig <tobias.koenig@nokia.com>
     */
    class XsdAnnotation : public NamedSchemaComponent
    {
        public:
            typedef QExplicitlySharedDataPointer<XsdAnnotation> Ptr;
            typedef QList<XsdAnnotation::Ptr> List;

            /**
             * Sets the @p id of the annotation.
             */
            void setId(const DerivedString<TypeID>::Ptr &id);

            /**
             * Returns the @p id of the annotation.
             */
            DerivedString<TypeID>::Ptr id() const;

            /**
             * Adds an application @p information to the annotation.
             *
             * The application information is meant to be interpreted by
             * a software system, e.g. other parts of the XML processor pipeline.
             */
            void addApplicationInformation(const XsdApplicationInformation::Ptr &information);

            /**
             * Returns the list of all application information of the annotation.
             */
            XsdApplicationInformation::List applicationInformation() const;

            /**
             * Adds a @p documentation to the annotation.
             *
             * The documentation is meant to be read by human being, e.g. additional
             * constraints or information about schema components.
             */
            void addDocumentation(const XsdDocumentation::Ptr &documentation);

            /**
             * Returns the list of all documentations of the annotation.
             */
            XsdDocumentation::List documentation() const;

        private:
            DerivedString<TypeID>::Ptr      m_id;
            XsdApplicationInformation::List m_applicationInformation;
            XsdDocumentation::List          m_documentations;
    };
}

QT_END_NAMESPACE

QT_END_HEADER

#endif
