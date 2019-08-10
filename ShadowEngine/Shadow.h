#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface Shadow : NSObject {
    NSMutableDictionary *path_exclusions;
    NSMutableDictionary *path_symlinks;
    NSMutableDictionary *path_rules;
    NSMutableSet *url_schemes;
}

+ (instancetype)shadowWithRules:(NSMutableDictionary *)rules url_schemes:(NSMutableSet *)url_schemes;

- (NSDictionary *)exportShadowData;

- (BOOL)isPathRestricted:(NSString *)path;
- (BOOL)isPathRestricted:(NSString *)path exact:(BOOL)exact;
- (BOOL)isURLRestricted:(NSURL *)url;
- (BOOL)isURLRestricted:(NSURL *)url exact:(BOOL)exact;

- (void)setDestinationOfLinkAtPath:(NSString *)path destination:(NSString *)destination;
- (NSString *)getDestinationOfLinkAtPath:(NSString *)path;

- (void)addPathExclusion:(NSString *)path amount:(NSNumber *)amount;
- (void)addRestrictedPath:(NSString *)path restricted:(BOOL)restricted exact_only:(BOOL)exact_only;
- (void)addRestrictedURLScheme:(NSString *)scheme;
- (void)addRules:(NSMutableDictionary *)rules;
- (void)addURLSchemes:(NSMutableSet *)url_schemes;

@end
