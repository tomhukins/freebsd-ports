--- chrome/browser/chrome_browser_main_linux.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/chrome_browser_main_linux.cc
@@ -25,7 +25,7 @@
 #include "device/bluetooth/dbus/bluez_dbus_thread_manager.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 
@@ -70,7 +70,9 @@ void ChromeBrowserMainPartsLinux::PostCreateMainMessag
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_BSD)
   bluez::BluezDBusManager::Initialize(nullptr /* system_bus */);
+#endif
 
   // Set up crypt config. This needs to be done before anything starts the
   // network service, as the raw encryption key needs to be shared with the
@@ -96,7 +98,7 @@ void ChromeBrowserMainPartsLinux::PostCreateMainMessag
   ChromeBrowserMainPartsPosix::PostCreateMainMessageLoop();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromeBrowserMainPartsLinux::PostMainMessageLoopRun() {
   ChromeBrowserMainPartsPosix::PostMainMessageLoopRun();
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
@@ -134,7 +136,7 @@ void ChromeBrowserMainPartsLinux::PostDestroyThreads()
 #endif  // BUILDFLAG(USE_DBUS) && !BUILDFLAG(IS_CHROMEOS)
 
 void ChromeBrowserMainPartsLinux::PostDestroyThreads() {
-#if BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // No-op; per PostBrowserStart() comment, this is done elsewhere.
 #else
   bluez::BluezDBusManager::Shutdown();
