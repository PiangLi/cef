// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CEF_LIBCEF_COMMON_EXTENSIONS_EXTENSIONS_API_PROVIDER_H_
#define CEF_LIBCEF_COMMON_EXTENSIONS_EXTENSIONS_API_PROVIDER_H_

#include "base/macros.h"
#include "chrome/common/extensions/permissions/chrome_api_permissions.h"
#include "extensions/common/extensions_api_provider.h"

namespace extensions {

class CefExtensionsAPIProvider : public ExtensionsAPIProvider {
 public:
  CefExtensionsAPIProvider();

  // ExtensionsAPIProvider:
  void AddAPIFeatures(FeatureProvider* provider) override;
  void AddManifestFeatures(FeatureProvider* provider) override;
  void AddPermissionFeatures(FeatureProvider* provider) override;
  void AddBehaviorFeatures(FeatureProvider* provider) override;
  void AddAPIJSONSources(JSONFeatureProviderSource* json_source) override;
  bool IsAPISchemaGenerated(const std::string& name) override;
  base::StringPiece GetAPISchema(const std::string& name) override;
  void AddPermissionsProviders(PermissionsInfo* permissions_info) override;
  void RegisterManifestHandlers() override;

 private:
  const ChromeAPIPermissions chrome_api_permissions_;

  DISALLOW_COPY_AND_ASSIGN(CefExtensionsAPIProvider);
};

}  // namespace extensions

#endif  // CEF_LIBCEF_COMMON_EXTENSIONS_EXTENSIONS_API_PROVIDER_H_
