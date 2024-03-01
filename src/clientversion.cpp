// Copyright (c) 2012-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <clientversion.h>

#include <tinyformat.h>


/**
 * Name of client reported in the 'version' message. Report the same name
 * for both qlinkd and qlink-qt, to make it harder for attackers to
 * target servers or GUI users specifically.
 */
const std::string CLIENT_NAME("Qlink Core");


#ifdef HAVE_BUILD_INFO
#include <obj/build.h>
// The <obj/build.h>, which is generated by the build environment (share/genbuild.sh),
// could contain only one line of the following:
//   - "#define BUILD_GIT_TAG ...", if the top commit is tagged
//   - "#define BUILD_GIT_COMMIT ...", if the top commit is not tagged
//   - "// No build information available", if proper git information is not available
#endif

//! git will put "#define GIT_COMMIT_ID ..." on the next line inside archives. 
#define GIT_COMMIT_ID ""

#ifdef BUILD_GIT_TAG
    #define BUILD_DESC BUILD_GIT_TAG
    #define BUILD_SUFFIX ""
#else
    #define BUILD_DESC "v" PACKAGE_VERSION
    #if CLIENT_VERSION_IS_RELEASE
        #define BUILD_SUFFIX ""
    #elif defined(BUILD_GIT_COMMIT)
        #define BUILD_SUFFIX "-" BUILD_GIT_COMMIT
    #elif defined(GIT_COMMIT_ID)
        #define BUILD_SUFFIX "-g" GIT_COMMIT_ID
    #else
        #define BUILD_SUFFIX "-unk"
    #endif
#endif

const std::string CLIENT_BUILD(BUILD_DESC BUILD_SUFFIX);

std::string FormatVersion(int nVersion)
{
    return strprintf("%d.%d.%d", nVersion / 10000, (nVersion / 100) % 100, nVersion % 100);
}

std::string FormatFullVersion()
{
    return CLIENT_BUILD;
}

/**
 * Format the subversion field according to BIP 14 spec (https://github.com/bitcoin/bips/blob/master/bip-0014.mediawiki)
 */
std::string FormatSubVersion(const std::string& name, int nClientVersion, const std::vector<std::string>& comments)
{
    std::ostringstream ss;
    ss << "/";
    ss << name << ":" << FormatVersion(nClientVersion);
    if (!comments.empty())
    {
        std::vector<std::string>::const_iterator it(comments.begin());
        ss << "(" << *it;
        for(++it; it != comments.end(); ++it)
            ss << "; " << *it;
        ss << ")";
    }
    ss << "/";
    return ss.str();
}
