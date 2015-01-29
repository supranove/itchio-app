#ifndef AUTHENTICATIONVIEW_H
#define AUTHENTICATIONVIEW_H

#include "abstractview.h"
#include "ui_authenticationview.h"
#include <QRegExpValidator>

namespace itchio {

class ModalDialog;
class Application;
class Authenticator;
class Settings;

class AuthenticationView Q_DECL_FINAL : public AbstractView
{
    Q_OBJECT
    friend class ModalDialog;
public:

    inline bool isResizable() const Q_DECL_OVERRIDE { return false; }
    inline bool isCentered() const Q_DECL_OVERRIDE { return true; }
private:
    AuthenticationView(ModalDialog& dialog, Application& application);
    void disableInputComponents(const bool disable = true);

    QString username() const;
    QString password() const;

    void setStatusMessage(const QString& message) const;

    Ui::AuthenticationView ui_;
    Authenticator& authenticator_;
    const Settings& settings_;
    const QRegExpValidator usernameValidator_;
    bool enableApiKeyAuthentication_;
private slots:
    void onInputChanged();
    void onAuthenticateButtonClicked();
    void onAuthenticationFailed(const QString& message);
};

} // namespace itchio

#endif // AUTHENTICATIONVIEW_H
