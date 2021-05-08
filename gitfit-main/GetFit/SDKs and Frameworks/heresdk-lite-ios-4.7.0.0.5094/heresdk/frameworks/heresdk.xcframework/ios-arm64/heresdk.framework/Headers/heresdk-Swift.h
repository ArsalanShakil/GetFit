// Generated by Apple Swift version 5.3.2 (swiftlang-1200.0.45 clang-1200.0.32.28)
#ifndef HERESDK_SWIFT_H
#define HERESDK_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreGraphics;
@import GLKit;
@import ObjectiveC;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="heresdk",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

@class NSCoder;
@class UITouch;
@class UIEvent;
@class CADisplayLink;

/// A view that can display a map.
/// <h2>Map tiles caching</h2>
/// <p>The map tiles cache stores the map data the user sees on the screen. It's mostly used for
/// speeding up the startup times, but it has an additional advantage of showing cached map content,
/// when a device looses connectivity. The map tiles cache stores all visible map data, which, apart
/// from vector tiles, includes traffic, satellite and raster data.</p>
/// <p>The maximum tiles cache size is defined by `SDKOptions.cacheSizeInBytes`. You can set it in
/// the app's plist file or when `SDKOptions` and `SDKNativeEngine` are created programmatically.
/// Please refer to the developer's guide for more information about how to do that.</p>
/// <p>The default value is 256 MB. Use 0 value, if you want to disable the caching at all. Already
/// cached tiles are not going to be evicted, if the cache is disabled. If you want to use cache
/// size other than default and you don't define it in the plist file, you have to set it every
/// time a `SDKOptions` instance is created.</p>
/// <p>The tiles cache is stored under `SDKOptions.cachePath` (which by default is the application's
/// standard internal cache location &lt;Application Home&gt;/Library/Caches) under the subdirectory
/// <i>&lt;Cache Version&gt;/&lt;Access Key ID&gt;/mapviewlite-tiles</i>. For more information about
/// fetching standard paths on iOS see
/// <a href="https://developer.apple.com/documentation/foundation/filemanager/1407726-urls">
/// FileManager.urls</a> method. You can also check out the
/// <a href="https://developer.apple.com/icloud/documentation/data-storage/index.html">
/// iOS Data Storage Guidelines</a>. Please also bear in mind that the cache directory can be swiped
/// by the system itself, if it needs to make a free space on a device. The maximum cache size is not
/// limited internally by the SDK. Once an app is removed from a user's device the cache is also
/// deleted, unless the cache path was changed to an external one.</p>
/// <p>If the tiles cache becomes full, the oldest tiles are replaced with the newest tiles.
/// Changing the maximum cache size between consecutive application launches does not necessarily
/// invalidate currently cached tiles. When the maximum cache size is increased, already saved
/// tiles are not removed. However when it's decreased, the oldest tiles may be eventually
/// evicted (depending on the cache fullness) and the effective cache size will be trimmed to
/// the selected maximum cache size. If the cache is disabled (by setting the maximum cache size
/// to 0), then saved tiles are not removed, but remain unused until you reenable the cache.
/// If you want to remove all already cached tiles, call `clearTilesCache`. If you want to get
/// the current cache size, call `tilesCacheSize`.</p>
IB_DESIGNABLE
SWIFT_CLASS("_TtC7heresdk11MapViewLite")
@interface MapViewLite : UIView
/// <p>Determines the current maximum tiles cache size in bytes. Default maximum cache size is defined
/// by `SDKOptions.cacheSizeInBytes` (which is the preferable way to set the maximum tiles cache size).
/// Use 0 value, if you want to disable the caching at all. This property is designed to be used in a
/// storyboard file.</p>
/// <p>See `MapViewLite` documentation to find out more details about tiles caching.</p>
@property (nonatomic) IBInspectable uint32_t maxTilesCacheSize SWIFT_DEPRECATED_MSG("Will be removed in v4.8.0, use `SDKOptions.cacheSizeInBytes` instead.");
/// Initializes MapViewLite instance with an empty frame rectangle.
/// By default tiles caching is turned on with the maximum size defined by <code>SDKOptions.cacheSizeInBytes</code>.
- (nonnull instancetype)init;
- (nonnull instancetype)initWithFrame:(CGRect)frame;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
/// :nodoc:
- (void)touchesBegan:(NSSet<UITouch *> * _Nonnull)touches withEvent:(UIEvent * _Nullable)event;
/// :nodoc:
- (void)touchesMoved:(NSSet<UITouch *> * _Nonnull)touches withEvent:(UIEvent * _Nullable)event;
/// :nodoc:
- (void)touchesEnded:(NSSet<UITouch *> * _Nonnull)touches withEvent:(UIEvent * _Nullable)event;
/// :nodoc:
- (void)touchesCancelled:(NSSet<UITouch *> * _Nonnull)touches withEvent:(UIEvent * _Nullable)event;
/// :nodoc:
- (void)didMoveToWindow;
/// :nodoc:
- (void)didMoveToSuperview;
/// :nodoc:
- (void)layoutSubviews;
/// :nodoc:
- (void)removeFromSuperview;
- (void)updateWithSender:(CADisplayLink * _Nonnull)sender;
@end


@class GLKView;

@interface MapViewLite (SWIFT_EXTENSION(heresdk)) <GLKViewDelegate>
- (void)glkView:(GLKView * _Nonnull)view drawInRect:(CGRect)rect;
@end


/// This class is used to initialize internals of the SDK.
/// Usually shouldn’t be used directly.
SWIFT_CLASS("_TtC7heresdk22SDKInternalInitializer")
@interface SDKInternalInitializer : NSObject
- (void)initializeInternalsIfNecessary;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif
