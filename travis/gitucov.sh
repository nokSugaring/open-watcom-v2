#!/bin/sh
# *****************************************************************
# gitucov.sh - update coverity_scan branch to trigger scan
# *****************************************************************

###################################################################
# 1. update GitHub repository coverity_scan branch by master branch
#

gitucov_proc1()
{
    if [ "$OWTRAVIS_DEBUG" = "1" ]; then
        GITVERBOSE1=-v
        GITVERBOSE2=-v
    else
        GITVERBOSE1=--quiet
        GITVERBOSE2=
    fi

    #
    cd ..
    rm -rf $TRAVIS_BUILD_DIR
    git clone $GITVERBOSE1 https://${GITHUB_TOKEN}@github.com/${TRAVIS_REPO_SLUG}.git $TRAVIS_BUILD_DIR
    cd $TRAVIS_BUILD_DIR
    #
    if [ "$OWTRAVIS_DEBUG" = "1" ]; then echo "** git checkout"; fi
    git checkout $OWBRANCH_COVERITY
    if [ "$OWTRAVIS_DEBUG" = "1" ]; then echo "** git merge"; fi
    git merge $GITVERBOSE1 $OWBRANCH
    if [ "$OWTRAVIS_DEBUG" = "1" ]; then echo "** git add"; fi
    git add $GITVERBOSE2 -A
    if [ "$OWTRAVIS_DEBUG" = "1" ]; then echo "** git commit"; fi
    git commit $GITVERBOSE1 -am "Travis CI update from $OWBRANCH branch"
    if [ "$OWTRAVIS_DEBUG" = "1" ]; then echo "** git push"; fi
    git push $GITVERBOSE1 -f origin $OWBRANCH_COVERITY
    #
    
    echo "gitucov.sh - done"
    
    return 0
}

gitucov_proc1 $*
