add_test( RatioArithmetic.plus /home/juliettej/Documents/libRationel/libRatio/build/myTest/myUnitTests [==[--gtest_filter=RatioArithmetic.plus]==] --gtest_also_run_disabled_tests)
set_tests_properties( RatioArithmetic.plus PROPERTIES WORKING_DIRECTORY /home/juliettej/Documents/libRationel/libRatio/build/myTest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( myUnitTests_TESTS RatioArithmetic.plus)
