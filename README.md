# super-kenlm-wrapper\n\n[![Build Status](https://travis-ci.org/wedgwoods/super-kenlm-wrapper.svg?branch=master)](https://travis-ci.org/wedgwoods/super-kenlm-wrapper)\n\nJava JNI wrapper for [kenlm](https://github.com/kpu/kenlm).\n\n## Installation\n\n* maven\n* cmake\n* boost\n\n```bash\nmvn clean install\n```\n\n## Basic Usage\n\n```java\nModel model = new Model("test.arpa", new Config());\nSystem.out.println(model.score("this is a sentenc