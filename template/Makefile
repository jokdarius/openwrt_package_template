include $(TOPDIR)/rules.mk

PKG_NAME:=template
PKG_VERSION:=1.0.0
PKG_RELEASE:=1
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/template
	SECTION:=base
	CATEGORY:=Base system
	TITLE:=Openwrt package template
endef

define Package/template/description
	Package template
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/template/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/template $(1)/usr/sbin/template
endef

$(eval $(call BuildPackage,template))