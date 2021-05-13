const mix = require('laravel-mix');

mix.js('views/components/main.js', 'public/js').react().setPublicPath('public');