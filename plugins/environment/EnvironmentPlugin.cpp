#include "EnvironmentPlugin.h"

#include <ScriptPlugin.h>

EXPORT_PLUGIN(EnvironmentPlugin)

const QString EnvironmentPlugin::PLUGIN_NAME("environment");
const int EnvironmentPlugin::PLUGIN_VERSION(1);

const QString EnvironmentPlugin::VARIABLE_NAME("Environment");

QString EnvironmentPlugin::name() const {
	return PLUGIN_NAME;
}

int EnvironmentPlugin::version() const {
	return PLUGIN_VERSION;
}

void EnvironmentPlugin::install(ScriptEngineInterface* engine) {
	engine_ = engine;
	engine_->globalObject().setProperty(VARIABLE_NAME, engine_->newQObject(this), QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void EnvironmentPlugin::uninstall() {
	engine_->globalObject().setProperty(VARIABLE_NAME, QScriptValue::UndefinedValue);
	engine_ = NULL;
}

bool EnvironmentPlugin::reload() {
	return engine_->reload();
}

bool EnvironmentPlugin::require(const QString& path) {
	return engine_->require(path);
}
